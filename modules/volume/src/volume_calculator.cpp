// Copyright 2018 Konakov Alexandr

#include "include/volume_calculator.h"
#include "include/volume.h"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <string>

VolumeCalculator::VolumeCalculator() : message_("") {}

void VolumeCalculator::help(const char* appname, const char* message) {
  message_ = std::string(message) +
             "Usage: volume [Option] [Required values]\n"
             "Option:"
             "\t-h\tshow this help message\n"
             "\t-s\tsphere, requires radius\n"
             "\t-b\tbox(or cube) requires width\n"
             "\t-c\tcylinder, requires radius and height\n"
             "Examples:\n"
             "\tvolume -s 5.1\n"
             "\tvolume -c 3.4 12.0";
}

bool VolumeCalculator::validateNumberOfArguments(int argc, const char** argv) {
  if ((argc <= 2) || (strlen(argv[1]) != 2) || (argv[1][0] != '-')) {
    help(argv[0]);
    return false;
  }
  if ((strspn(&argv[1][1], "scb") == 0)) {
    help(argv[0]);
    return false;
  } else {
    switch (argv[1][1]) {
      case 'c':
        if (argc != 4) {
          help(argv[0]);
          return false;
        }
        break;
      default:
        if (argc != 3) {
          help(argv[0]);
          return false;
        }
    }
  }
  return true;
}

double parseDouble(const char* arg) {
  char* end;
  double value = strtod(arg, &end);

  if (end[0]) {
    throw std::string("Wrong number format!");
  }

  return value;
}

std::string VolumeCalculator::operator()(int argc, const char** argv) {
  Arguments args;
  args.radius = args.height = 0.0;
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  try {
    switch (argv[1][1]) {
      case 'b':
        args.height = parseDouble(argv[2]);
        break;
      case 's':
        args.radius = parseDouble(argv[2]);
        break;
      default:
        args.radius = parseDouble(argv[2]);
        args.height = parseDouble(argv[3]);
    }
  } catch (std::string& str) {
    return str;
  }

  std::ostringstream stream;
  try {
    stream << "Volume = ";
    switch (argv[1][1]) {
      case 's': {
        Sphere s(args.radius);
        stream << s.Volume();
        break;
      }
      case 'b': {
        Cube c(args.height);
        stream << c.Volume();
        break;
      }
      case 'c': {
        Cylinder c(args.radius, args.height);
        stream << c.Volume();
        break;
      }
    }
  } catch (std::string& str) {
    return str;
  }
  message_ = stream.str();
  return message_;
}
