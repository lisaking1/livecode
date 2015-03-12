/* Copyright (C) 2003-2013 Runtime Revolution Ltd.
 
 This file is part of LiveCode.
 
 LiveCode is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License v3 as published by the Free
 Software Foundation.
 
 LiveCode is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 for more details.
 
 You should have received a copy of the GNU General Public License
 along with LiveCode.  If not see <http://www.gnu.org/licenses/>.  */

#include <foundation.h>
#include "foundation-math.h"
#include <foundation-system.h>

#include <float.h>
#include <errno.h>

// Older versions of MSVC don't supply "trunc"
#ifdef _WIN32
double trunc(double f) { return f < 0 ? ceil(f) : floor(f); }
#endif

////////////////////////////////////////////////////////////////

MCTypeInfoRef kMCMathDomainErrorTypeInfo;

////////////////////////////////////////////////////////////////

extern "C" MC_DLLEXPORT void MCMathEvalRealToPowerOfReal(double p_left, double p_right, double& r_output)
{
	errno = 0;
    r_output = pow(p_left, p_right);

	if (errno == EDOM)
	{
		MCErrorCreateAndThrow (kMCMathDomainErrorTypeInfo, nil);
	}
}

extern "C" MC_DLLEXPORT void MCMathEvalNumberToPowerOfNumber(MCNumberRef p_left, MCNumberRef p_right, MCNumberRef& r_output)
{
    double t_left, t_right;
    t_left = MCNumberFetchAsReal(p_left);
    t_right = MCNumberFetchAsReal(p_right);
    
    double t_result;
    MCMathEvalRealToPowerOfReal(t_left, t_right, t_result);
    
    // if (!ctxt . HasError())
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalBase10LogReal(double p_operand, double& r_output)
{
	errno = 0;
    r_output = log10(p_operand);

	if (errno == EDOM)
	{
		MCErrorCreateAndThrow (kMCMathDomainErrorTypeInfo, nil);
	}
}

extern "C" MC_DLLEXPORT void MCMathEvalBase10LogNumber(MCNumberRef p_operand, MCNumberRef& r_output)
{
    double t_operand;
    t_operand = MCNumberFetchAsReal(p_operand);
    
    double t_result;
    MCMathEvalBase10LogReal(t_operand, t_result);
    
    // if (!ctxt . HasError())
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalNaturalLogReal(double p_operand, double& r_output)
{
	errno = 0;
    r_output = log(p_operand);

	if (errno == EDOM)
	{
		MCErrorCreateAndThrow (kMCMathDomainErrorTypeInfo, nil);
	}
}

extern "C" MC_DLLEXPORT void MCMathEvalNaturalLogNumber(MCNumberRef p_operand, MCNumberRef& r_output)
{
    double t_operand;
    t_operand = MCNumberFetchAsReal(p_operand);
    
    double t_result;
    MCMathEvalNaturalLogReal(t_operand, t_result);
    
    // if (!ctxt . HasError())
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalExpReal(double p_operand, double& r_output)
{
    r_output = exp(p_operand);
}

extern "C" MC_DLLEXPORT void MCMathEvalExpNumber(MCNumberRef p_operand, MCNumberRef& r_output)
{
    double t_operand;
    t_operand = MCNumberFetchAsReal(p_operand);
    
    double t_result;
    MCMathEvalExpReal(t_operand, t_result);
    
    // if (!ctxt . HasError())
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalSinReal(double p_operand, double& r_output)
{
    r_output = sin(p_operand);
}

extern "C" MC_DLLEXPORT void MCMathEvalSinNumber(MCNumberRef p_operand, MCNumberRef& r_output)
{
    double t_operand;
    t_operand = MCNumberFetchAsReal(p_operand);
    
    double t_result;
    MCMathEvalSinReal(t_operand, t_result);
    
    // if (!ctxt . HasError())
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalCosReal(double p_operand, double& r_output)
{
    r_output = cos(p_operand);
}

extern "C" MC_DLLEXPORT void MCMathEvalCosNumber(MCNumberRef p_operand, MCNumberRef& r_output)
{
    double t_operand;
    t_operand = MCNumberFetchAsReal(p_operand);
    
    double t_result;
    MCMathEvalCosReal(t_operand, t_result);
    
    // if (!ctxt . HasError())
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalTanReal(double p_operand, double& r_output)
{
    r_output = tan(p_operand);
}

extern "C" MC_DLLEXPORT void MCMathEvalTanNumber(MCNumberRef p_operand, MCNumberRef& r_output)
{
    double t_operand;
    t_operand = MCNumberFetchAsReal(p_operand);
    
    double t_result;
    MCMathEvalTanReal(t_operand, t_result);
    
    // if (!ctxt . HasError())
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalAsinReal(double p_operand, double& r_output)
{
    r_output = asin(p_operand);
}

extern "C" MC_DLLEXPORT void MCMathEvalAsinNumber(MCNumberRef p_operand, MCNumberRef& r_output)
{
    double t_operand;
    t_operand = MCNumberFetchAsReal(p_operand);
    
    double t_result;
    MCMathEvalAsinReal(t_operand, t_result);
    
    // if (!ctxt . HasError())
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalAcosReal(double p_operand, double& r_output)
{
    r_output = acos(p_operand);
}

extern "C" MC_DLLEXPORT void MCMathEvalAcosNumber(MCNumberRef p_operand, MCNumberRef& r_output)
{
    double t_operand;
    t_operand = MCNumberFetchAsReal(p_operand);
    
    double t_result;
    MCMathEvalAcosReal(t_operand, t_result);
    
    // if (!ctxt . HasError())
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalAtanReal(double p_operand, double& r_output)
{
    r_output = atan(p_operand);
}

extern "C" MC_DLLEXPORT void MCMathEvalAtanNumber(MCNumberRef p_operand, MCNumberRef& r_output)
{
    double t_operand;
    t_operand = MCNumberFetchAsReal(p_operand);
    
    double t_result;
    MCMathEvalAtanReal(t_operand, t_result);
    
    // if (!ctxt . HasError())
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalAtan2Real(double p_first, double p_second, double& r_output)
{
    r_output = atan2(p_first, p_second);
}

extern "C" MC_DLLEXPORT void MCMathEvalAtan2Number(MCNumberRef p_first, MCNumberRef p_second, MCNumberRef& r_output)
{
    double t_first, t_second;
    t_first = MCNumberFetchAsReal(p_first);
    t_second = MCNumberFetchAsReal(p_second);
    
    double t_result;
    MCMathEvalAtan2Real(t_first, t_second, t_result);
    
    // if (!ctxt . HasError())
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalAbsInteger(integer_t p_operand, integer_t& r_output)
{
    r_output = MCAbs(p_operand);
}

extern "C" MC_DLLEXPORT void MCMathEvalAbsReal(double p_operand, double& r_output)
{
    r_output = MCAbs(p_operand);
}

extern "C" MC_DLLEXPORT void MCMathEvalAbsNumber(MCNumberRef p_operand, MCNumberRef& r_output)
{
    if (MCNumberIsInteger(p_operand))
    {
        integer_t t_abs;
        MCMathEvalAbsInteger(MCNumberFetchAsInteger(p_operand), t_abs);
        MCNumberCreateWithInteger(t_abs, r_output);
        return;
    }
    
    double t_abs_real;
    MCMathEvalAbsReal(MCNumberFetchAsReal(p_operand), t_abs_real);
    MCNumberCreateWithReal(t_abs_real, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalTruncInteger(integer_t p_operand, integer_t& r_output)
{
    r_output = p_operand;
}

extern "C" MC_DLLEXPORT void MCMathEvalTruncReal(double p_operand, double& r_output)
{
    r_output = trunc(p_operand);
}

extern "C" MC_DLLEXPORT void MCMathEvalTruncNumber(MCNumberRef p_operand, MCNumberRef& r_output)
{
    if (MCNumberIsInteger(p_operand))
    {
        integer_t t_abs;
        MCMathEvalTruncInteger(MCNumberFetchAsInteger(p_operand), t_abs);
        MCNumberCreateWithInteger(t_abs, r_output);
        return;
    }
    
    double t_abs_real;
    MCMathEvalTruncReal(MCNumberFetchAsReal(p_operand), t_abs_real);
    MCNumberCreateWithReal(t_abs_real, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalMinInteger(integer_t p_left, integer_t p_right, integer_t& r_output)
{
    r_output = MCMin(p_left, p_right);
}

extern "C" MC_DLLEXPORT void MCMathEvalMinReal(double p_left, double p_right, double& r_output)
{
    r_output = MCMin(p_left, p_right);
}

extern "C" MC_DLLEXPORT void MCMathEvalMinNumber(MCNumberRef p_left, MCNumberRef p_right, MCNumberRef& r_output)
{
    double t_left, t_right, t_result;
    t_left = MCNumberFetchAsReal(p_left);
    t_right = MCNumberFetchAsReal(p_right);
    
    MCMathEvalMinReal(t_left, t_right, t_result);
    
    MCNumberCreateWithReal(t_result, r_output);
}

static void MCMathEvalMinMaxList(MCProperListRef p_list, bool p_is_min, MCNumberRef& r_output)
{
    if (MCProperListIsEmpty(p_list))
        MCErrorCreateAndThrow(kMCGenericErrorTypeInfo, "reason", MCSTR("list must be non-empty"), nil);
    
    if (!MCProperListIsListOfType(p_list, kMCValueTypeCodeNumber))
        MCErrorCreateAndThrow(kMCGenericErrorTypeInfo, "reason", MCSTR("list must be numeric"), nil);

    double t_minmax, t_cur_real;
    t_cur_real = MCNumberFetchAsReal((MCNumberRef)MCProperListFetchElementAtIndex(p_list, 0));
    t_minmax = t_cur_real;
    
    bool t_replace;
    for (uindex_t i = 1; i < MCProperListGetLength(p_list); i++)
    {
        t_cur_real = MCNumberFetchAsReal((MCNumberRef)MCProperListFetchElementAtIndex(p_list, i));
        t_replace = p_is_min ? t_cur_real < t_minmax : t_cur_real > t_minmax;

        if (t_replace)
            t_minmax = t_cur_real;
    }
    
    MCNumberCreateWithReal(t_minmax, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalMinList(MCProperListRef p_list, MCNumberRef& r_output)
{
    MCMathEvalMinMaxList(p_list, true, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalMaxList(MCProperListRef p_list, MCNumberRef& r_output)
{
    MCMathEvalMinMaxList(p_list, false, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalMaxInteger(integer_t p_left, integer_t p_right, integer_t& r_output)
{
    r_output = MCMax(p_left, p_right);
}

extern "C" MC_DLLEXPORT void MCMathEvalMaxReal(double p_left, double p_right, double& r_output)
{
    r_output = MCMax(p_left, p_right);
}

extern "C" MC_DLLEXPORT void MCMathEvalMaxNumber(MCNumberRef p_left, MCNumberRef p_right, MCNumberRef& r_output)
{
    double t_left, t_right, t_result;
    t_left = MCNumberFetchAsReal(p_left);
    t_right = MCNumberFetchAsReal(p_right);
    
    MCMathEvalMaxReal(t_left, t_right, t_result);
    
    MCNumberCreateWithReal(t_result, r_output);
}

extern "C" MC_DLLEXPORT void MCMathEvalRandomReal(double& r_output)
{
    r_output = MCSRandomReal();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" MC_DLLEXPORT void MCMathEvalConvertToBase10(MCStringRef p_operand, integer_t p_source_base, integer_t& r_output)
{
    if (p_source_base < 2 || p_source_base > 32)
        MCErrorCreateAndThrow(kMCGenericErrorTypeInfo, "reason", MCSTR("source base must be between 2 and 32"), nil);
    
    bool t_negative;
    uinteger_t t_result;
    bool t_error;
    if (MCMathConvertToBase10(p_operand, p_source_base, t_negative, t_result, t_error))
    {
        if ((t_negative && t_result > INTEGER_MAX) || (!t_negative && t_result > abs(INTEGER_MIN)))
            MCErrorCreateAndThrow(kMCGenericErrorTypeInfo, "reason", MCSTR("integer overflow"), nil);
        else
            r_output = t_negative ? -t_result : t_result;
    }
}

extern "C" MC_DLLEXPORT void MCMathEvalConvertFromBase10(integer_t p_operand, integer_t p_dest_base, MCStringRef& r_output)
{
    if (p_dest_base < 2 || p_dest_base > 32)
        MCErrorCreateAndThrow(kMCGenericErrorTypeInfo, "reason", MCSTR("destination base must be between 2 and 32"), nil);
    
    if (p_operand < 0)
    {
        if (MCMathConvertFromBase10(-p_operand, true, p_dest_base, r_output))
            return;
    }
    else
    {
        if (MCMathConvertFromBase10(p_operand, false, p_dest_base, r_output))
            return;
    }
    
//    ctxt . Throw();
}

extern "C" MC_DLLEXPORT void MCMathEvalConvertBase(MCStringRef p_operand, integer_t p_source_base, integer_t p_dest_base, MCStringRef& r_output)
{
    
    if (p_source_base < 2 || p_source_base > 32)
        MCErrorCreateAndThrow(kMCGenericErrorTypeInfo, "reason", MCSTR("source base must be between 2 and 32"), nil);
    
    if (p_dest_base < 2 || p_dest_base > 32)
        MCErrorCreateAndThrow(kMCGenericErrorTypeInfo, "reason", MCSTR("destination base must be between 2 and 32"), nil);
    
    bool t_negative;
    uinteger_t t_result;
    bool t_error;
    if (MCMathConvertToBase10(p_operand, p_source_base, t_negative, t_result, t_error))
    {
        if (MCMathConvertFromBase10(t_result, t_negative, p_dest_base, r_output))
            return;
    }
    
    // If t_error is false then we failed because of a memory error, so no need to throw
    if (t_error)
        MCErrorCreateAndThrow(kMCGenericErrorTypeInfo, "reason", MCSTR("integer overflow, or invalid character in source"), nil);
}

////////////////////////////////////////////////////////////////

bool
MCMathModuleInitialize (void)
{
	if (!MCNamedErrorTypeInfoCreate (MCNAME("com.livecode.math.DomainError"), MCNAME("math"), MCSTR("mathematical function domain error"), kMCMathDomainErrorTypeInfo))
		return false;

	return true;
}

void
MCMathModuleFinalize (void)
{
	MCValueRelease (kMCMathDomainErrorTypeInfo);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
