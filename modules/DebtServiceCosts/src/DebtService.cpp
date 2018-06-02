// Copyright 2018 Vyunov Roman

#include "../modules/DebtServiceCosts/include/DebtService.h"

DebtService::DebtService(float loan_amount, int loan_term,
                         float loan_rate, DebtServiceType dt) {
    if (loan_amount < 0) {
        throw "Incorrect amount";
    } else {
        loan_amount_ = loan_amount;
    }

    if (loan_term < 1) {
        throw "Incorrect term";
    } else {
        loan_term_ = loan_term;
    }

    if (loan_rate < 0) {
        throw "Incorrect rate";
    } else {
        loan_rate_ = loan_rate;
    }
    curr_term_ = 0;
    service_type_ = dt;
    loan_balance_ = GetTotalPayout();
}

DebtService::DebtService(const DebtService &ds) {
    loan_amount_ = ds.loan_amount_;
    loan_balance_ = ds.loan_balance_;
    loan_rate_ = ds.loan_rate_;
    loan_term_ = ds.loan_term_;
    service_type_ = ds.service_type_;
    curr_term_ = ds.curr_term_;
}

DebtService& DebtService::operator=(const DebtService& dt) {
    loan_amount_ = dt.loan_amount_;
    loan_balance_ = dt.loan_balance_;
    loan_rate_ = dt.loan_rate_;
    loan_term_ = dt.loan_term_;
    service_type_ = dt.service_type_;
    curr_term_ = dt.curr_term_;

    return *this;
}

bool DebtService::operator==(const DebtService& ds) const {
    return loan_amount_ == ds.loan_amount_ &&
            loan_balance_ == ds.loan_balance_ &&
            loan_rate_ == ds.loan_rate_ &&
            loan_term_ == ds.loan_term_ &&
            curr_term_ == ds.curr_term_ &&
            service_type_ == ds.service_type_;
}

float DebtService::GetTotalPayout() const {
    float tmp = -1;

    switch (service_type_) {
    case ONE_PAYMENT_AT_THE_END:
        tmp = loan_amount_ * pow(1 + loan_rate_, loan_term_);
        break;
    case PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END:
        tmp = loan_amount_ * (1 + loan_term_ * loan_rate_);
        break;
    case EQUAL_ANNUAL_PAYMENTS:
        tmp = loan_amount_ * (1 + loan_term_ * loan_rate_) -
                loan_amount_ * (loan_rate_ * (loan_term_ - 1)/2);
        break;
    }

    return tmp;
}

void DebtService::MakingPayment(float pay_amnt) {
    switch (service_type_) {
    case ONE_PAYMENT_AT_THE_END:
        Making1PaymentEnd(pay_amnt);
        break;
    case PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END:
        MakingPrincipal1PaymentEnd(pay_amnt);
        break;
    case EQUAL_ANNUAL_PAYMENTS:
        MakingEqualAnnualPayments(pay_amnt);
        break;
    }
}

float DebtService::GetBalance() {
    return loan_balance_;
}

void DebtService::Making1PaymentEnd(float pay_amnt) {
    if (pay_amnt == loan_balance_)
        loan_balance_ -= pay_amnt;
    else
        throw "Must pay another amount";
}

void DebtService::MakingPrincipal1PaymentEnd(float pay_amnt) {
    if (curr_term_ < loan_term_ - 1 &&
            pay_amnt == loan_amount_ * loan_rate_) {
        loan_balance_ -= pay_amnt;
        curr_term_ += 1;
    } else if (curr_term_ == loan_rate_ - 1 &&
            pay_amnt == loan_amount_ * (1 + loan_rate_)) {
        loan_balance_ -= pay_amnt;
        curr_term_ += 1;
    } else {
        throw "Must pay another amount";
    }
}

void DebtService::MakingEqualAnnualPayments(float pay_amnt) {
    if (pay_amnt == loan_amount_ *
            (1 + loan_rate_ * (loan_term_ - curr_term_))/loan_term_) {
        loan_balance_ -= pay_amnt;
        curr_term_ += 1;
    } else {
        throw "Must pay another amount";
    }
}
