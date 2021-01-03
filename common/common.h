#pragma once

#include "noncopyable.h"
#include "singleton.h"
#include "Exceptions.h"

#define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember))