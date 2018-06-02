// Copyright 2018 Vyunov Roman

#include <gtest/gtest.h>

#include "../modules/DebtServiceCosts/include/DebtService.h"

TEST(Vyunov_Roman_DebtService_test, Can_Throw_Exception_Incorrect_Amount) {
    // Act & Assert
    ASSERT_ANY_THROW(new DebtService(-1.0, 2.0, 3.0, ONE_PAYMENT_AT_THE_END));
}

TEST(Vyunov_Roman_DebtService_test, Can_Throw_Exception_Incorrect_Term) {
    // Act & Assert
    ASSERT_ANY_THROW(new DebtService(1.0, -2.0, 3.0, ONE_PAYMENT_AT_THE_END));
}

TEST(Vyunov_Roman_DebtService_test, Can_Throw_Exception_Incorrect_Rate) {
    // Act & Assert
    ASSERT_ANY_THROW(new DebtService(1.0, 2.0, -3.0, ONE_PAYMENT_AT_THE_END));
}

TEST(Vyunov_Roman_DebtService_test, Copy_constructor_work_correctly) {
    // Arrange
    DebtService ds1(1, 1, 1, ONE_PAYMENT_AT_THE_END);
    // Act
    DebtService ds2(ds1);
    // Assert
    ASSERT_EQ(ds1, ds2);
}

TEST(Vyunov_Roman_DebtService_test, Equal_operator_work_correctly) {
    // Arrange
    DebtService ds1(1, 1, 1, ONE_PAYMENT_AT_THE_END);
    DebtService ds2(1, 2, 3, EQUAL_ANNUAL_PAYMENTS);
    // Act
    ds1 = ds2;
    // Assert
    ASSERT_EQ(ds1, ds2);
}

TEST(Vyunov_Roman_DebtService_test, Equal_operator_return_correct_value) {
    // Arrange
    DebtService ds1(1, 1, 1, ONE_PAYMENT_AT_THE_END);
    DebtService ds2(1, 2, 3, EQUAL_ANNUAL_PAYMENTS);
    // Act & Assert
    ASSERT_EQ(&ds1, &(ds1 = ds2));
}

TEST(Vyunov_Roman_DebtService_test, GetTotalPayout_for_ONE_PAYMENT_AT_THE_END) {
    // Arrange
    DebtService ds1(1, 1, 1, ONE_PAYMENT_AT_THE_END);
    // Act & Assert
    ASSERT_EQ(ds1.GetTotalPayout(), 2);
}

TEST(Vyunov_Roman_DebtService_test,
     GetTotalPayout_for_PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END) {
    // Arrange
    DebtService ds1(1, 1, 1, PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END);
    // Act & Assert
    ASSERT_EQ(ds1.GetTotalPayout(), 2);
}

TEST(Vyunov_Roman_DebtService_test, GetTotalPayout_for_EQUAL_ANNUAL_PAYMENTS) {
    // Arrange
    DebtService ds1(1, 1, 1, EQUAL_ANNUAL_PAYMENTS);
    // Act & Assert
    ASSERT_EQ(ds1.GetTotalPayout(), 2);
}

TEST(Vyunov_Roman_DebtService_test, MakingPayment_for_ONE_PAYMENT_AT_THE_END) {
    // Arrange
    DebtService ds1(1, 1, 1, ONE_PAYMENT_AT_THE_END);
    // Act
    ds1.MakingPayment(2);
    // Assert
    ASSERT_EQ(ds1.GetBalance(), 0);
}

TEST(Vyunov_Roman_DebtService_test,
     MakingPayment_throw_exception_for_ONE_PAYMENT_AT_THE_END) {
    // Arrange
    DebtService ds1(1, 1, 1, ONE_PAYMENT_AT_THE_END);
    // Act & Assert
    ASSERT_ANY_THROW(ds1.MakingPayment(1));
}

TEST(Vyunov_Roman_DebtService_test,
     MakingPayment_in_1_year_for_PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END) {
    // Arrange
    DebtService ds1(1, 2, 1, PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END);
    // Act
    ds1.MakingPayment(1);
    // Assert
    ASSERT_EQ(ds1.GetBalance(), 2);
}

TEST(Vyunov_Roman_DebtService_test,
     MakingPayment_for_PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END) {
    // Arrange
    DebtService ds1(1, 1, 1, PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END);
    // Act
    ds1.MakingPayment(2);
    // Assert
    ASSERT_EQ(ds1.GetBalance(), 0);
}

TEST(Vyunov_Roman_DebtService_test,
     MakingPayment_throw_exception_for_PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END) {
    // Arrange
    DebtService ds1(1, 1, 1, PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END);
    // Act & Assert
    ASSERT_ANY_THROW(ds1.MakingPayment(1));
}

TEST(Vyunov_Roman_DebtService_test,
     MakingPayment_for_EQUAL_ANNUAL_PAYMENTS) {
    // Arrange
    DebtService ds1(1, 1, 1, EQUAL_ANNUAL_PAYMENTS);
    // Act
    ds1.MakingPayment(2);
    // Assert
    ASSERT_EQ(ds1.GetBalance(), 0);
}

TEST(Vyunov_Roman_DebtService_test,
     MakingPayment_throw_exception_for_EQUAL_ANNUAL_PAYMENTS) {
    // Arrange
    DebtService ds1(1, 1, 1, EQUAL_ANNUAL_PAYMENTS);
    // Act & Assert
    ASSERT_ANY_THROW(ds1.MakingPayment(1));
}
