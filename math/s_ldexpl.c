/* s_ldexpl.c -- long double version of s_ldexp.c.
 * Conversion to long double by Ulrich Drepper,
 * Cygnus Support, drepper@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

#if defined(LIBM_SCCS) && !defined(lint)
static char rcsid[] = "$NetBSD: $";
#endif

#include <math.h>
#include <math_private.h>
#include <errno.h>

long double __ldexpl(long double value, int exp)
{
	if(!isfinite(value)||value==0.0) return value;
	value = __scalbnl(value,exp);
	if(!isfinite(value)||value==0.0) __set_errno (ERANGE);
	return value;
}
weak_alias (__ldexpl, ldexpl)
weak_alias (__ldexpl, scalbnl)
