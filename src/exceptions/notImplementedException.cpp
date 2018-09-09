/*
 * notImplementedException.cpp
 *
 *  Created on: Dec 17, 2017
 *      Author: stoffer
 */

#include <exception>
#include <string>
#include "exceptions/notImplementedException.hpp"

namespace std
{
  NotImplementedException::NotImplementedException(const char * error /*=
      "Functionality not yet implemented!"*/)
  {
    errorMessage = error;
  }

  const char * NotImplementedException::what() const noexcept
  {
    return errorMessage.c_str();
  }
}

