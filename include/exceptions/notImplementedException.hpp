/*
 * notImplementedException.hpp
 *
 *  Created on: Dec 17, 2017
 *      Author: stoffer
 */

#pragma once

#include <exception>
#include <string>

namespace std
{
  class NotImplementedException : public std::exception {
  public:
      // Construct with given error message:
      NotImplementedException(const char * error = "Functionality not yet implemented!");

      // Provided for compatibility with std::exception.
      const char * what() const noexcept;
  private:
       std::string errorMessage;
  };
}
