/* stdio.h library for large systems - small embedded systems use clibrary.c instead */
#include "../interpreter.h"

#ifndef BUILTIN_MINI_STDLIB
#ifndef NO_FP

static double M_EValue =        2.7182818284590452354;   /* e */
static double M_LOG2EValue =    1.4426950408889634074;   /* log_2 e */
static double M_LOG10EValue =   0.43429448190325182765;  /* log_10 e */
static double M_LN2Value =      0.69314718055994530942;  /* log_e 2 */
static double M_LN10Value =     2.30258509299404568402;  /* log_e 10 */
static double M_PIValue =       3.14159265358979323846;  /* pi */
static double M_PI_2Value =     1.57079632679489661923;  /* pi/2 */
static double M_PI_4Value =     0.78539816339744830962;  /* pi/4 */
static double M_1_PIValue =     0.31830988618379067154;  /* 1/pi */
static double M_2_PIValue =     0.63661977236758134308;  /* 2/pi */
static double M_2_SQRTPIValue = 1.12837916709551257390;  /* 2/sqrt(pi) */
static double M_SQRT2Value =    1.41421356237309504880;  /* sqrt(2) */
static double M_SQRT1_2Value =  0.70710678118654752440;  /* 1/sqrt(2) */


void MathSin(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = sin(Param[0]->Val->FP64);
}

void MathCos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = cos(Param[0]->Val->FP64);
}

void MathTan(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = tan(Param[0]->Val->FP64);
}

void MathAsin(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = asin(Param[0]->Val->FP64);
}

void MathAcos(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = acos(Param[0]->Val->FP64);
}

void MathAtan(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = atan(Param[0]->Val->FP64);
}

void MathAtan2(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = atan2(Param[0]->Val->FP64, Param[1]->Val->FP64);
}

void MathSinh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = sinh(Param[0]->Val->FP64);
}

void MathCosh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = cosh(Param[0]->Val->FP64);
}

void MathTanh(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = tanh(Param[0]->Val->FP64);
}

void MathExp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = exp(Param[0]->Val->FP64);
}

void MathFabs(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = fabs(Param[0]->Val->FP64);
}

void MathFmod(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = fmod(Param[0]->Val->FP64, Param[1]->Val->FP64);
}

void MathFrexp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = frexp(Param[0]->Val->FP64, Param[1]->Val->Pointer);
}

void MathLdexp(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = ldexp(Param[0]->Val->FP64, Param[1]->Val->Integer);
}

void MathLog(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = log(Param[0]->Val->FP64);
}

void MathLog10(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = log10(Param[0]->Val->FP64);
}

void MathModf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = modf(Param[0]->Val->FP64, Param[0]->Val->Pointer);
}

void MathPow(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = pow(Param[0]->Val->FP64, Param[1]->Val->FP64);
}

void MathSqrt(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = sqrt(Param[0]->Val->FP64);
}

void MathRound(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    /* this awkward definition of "round()" due to it being inconsistently
     * declared in math.h */
    ReturnValue->Val->FP64 = ceil(Param[0]->Val->FP64 - 0.5);
}

void MathCeil(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = ceil(Param[0]->Val->FP64);
}

void MathFloor(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP64 = floor(Param[0]->Val->FP64);
}

// float
void MathSinf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = sinf(Param[0]->Val->FP32);
}

void MathCosf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = cosf(Param[0]->Val->FP32);
}

void MathTanf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = tanf(Param[0]->Val->FP32);
}

void MathAsinf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = asinf(Param[0]->Val->FP32);
}

void MathAcosf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = acosf(Param[0]->Val->FP32);
}

void MathAtanf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = atanf(Param[0]->Val->FP32);
}

void MathAtan2f(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = atan2f(Param[0]->Val->FP32, Param[1]->Val->FP32);
}

void MathSinhf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = sinhf(Param[0]->Val->FP32);
}

void MathCoshf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = coshf(Param[0]->Val->FP32);
}

void MathTanhf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = tanhf(Param[0]->Val->FP32);
}

void MathExpf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = expf(Param[0]->Val->FP32);
}

void MathFabsf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = fabsf(Param[0]->Val->FP32);
}

void MathFmodf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = fmodf(Param[0]->Val->FP32, Param[1]->Val->FP32);
}

void MathFrexpf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = frexpf(Param[0]->Val->FP32, Param[1]->Val->Pointer);
}

void MathLdexpf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = ldexpf(Param[0]->Val->FP32, Param[1]->Val->Integer);
}

void MathLogf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = logf(Param[0]->Val->FP32);
}

void MathLog10f(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = log10f(Param[0]->Val->FP32);
}

void MathModff(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = modff(Param[0]->Val->FP32, Param[0]->Val->Pointer);
}

void MathPowf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = powf(Param[0]->Val->FP32, Param[1]->Val->FP32);
}

void MathSqrtf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = sqrtf(Param[0]->Val->FP32);
}

void MathRoundf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    /* this awkward definition of "roundf()" due to it being inconsistently
     * declared in math.h */
    ReturnValue->Val->FP32 = ceilf(Param[0]->Val->FP32 - 0.5);
}

void MathCeilf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = ceilf(Param[0]->Val->FP32);
}

void MathFloorf(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
    ReturnValue->Val->FP32 = floorf(Param[0]->Val->FP32);
}
/* all math.h functions */
struct LibraryFunction MathFunctions[] =
{
    { MathAcos,         "double acos(double);" },
    { MathAsin,         "double asin(double);" },
    { MathAtan,         "double atan(double);" },
    { MathAtan2,        "double atan2(double, double);" },
    { MathCeil,         "double ceil(double);" },
    { MathCos,          "double cos(double);" },
    { MathCosh,         "double cosh(double);" },
    { MathExp,          "double exp(double);" },
    { MathFabs,         "double fabs(double);" },
    { MathFloor,        "double floor(double);" },
    { MathFmod,         "double fmod(double, double);" },
    { MathFrexp,        "double frexp(double, int *);" },
    { MathLdexp,        "double ldexp(double, int);" },
    { MathLog,          "double log(double);" },
    { MathLog10,        "double log10(double);" },
    { MathModf,         "double modf(double, double *);" },
    { MathPow,          "double pow(double,double);" },
    { MathRound,        "double round(double);" },
    { MathSin,          "double sin(double);" },
    { MathSinh,         "double sinh(double);" },
    { MathSqrt,         "double sqrt(double);" },
    { MathTan,          "double tan(double);" },
    { MathTanh,         "double tanh(double);" },
    { MathAcosf,         "float acosf(float);" },
    { MathAsinf,         "float asinf(float);" },
    { MathAtanf,         "float atanf(float);" },
    { MathAtan2f,        "float atan2f(float, float);" },
    { MathCeilf,         "float ceilf(float);" },
    { MathCosf,          "float cosf(float);" },
    { MathCoshf,         "float coshf(float);" },
    { MathExpf,          "float expf(float);" },
    { MathFabsf,         "float fabsf(float);" },
    { MathFloorf,        "float floorf(float);" },
    { MathFmodf,         "float fmodf(float, float);" },
    { MathFrexpf,        "float frexpf(float, int *);" },
    { MathLdexpf,        "float ldexpf(float, int);" },
    { MathLogf,          "float logf(float);" },
    { MathLog10f,        "float log10f(float);" },
    { MathModff,         "float modff(float, float *);" },
    { MathPowf,          "float powf(float,float);" },
    { MathRoundf,        "float roundf(float);" },
    { MathSinf,          "float sinf(float);" },
    { MathSinhf,         "float sinhf(float);" },
    { MathSqrtf,         "float sqrtf(float);" },
    { MathTanf,          "float tanf(float);" },
    { MathTanhf,         "float tanhf(float);" },
    { NULL,             NULL }
};

/* creates various system-dependent definitions */
void MathSetupFunc(Picoc *pc)
{
    VariableDefinePlatformVar(pc, NULL, "M_E", &pc->FP64Type, (union AnyValue *)&M_EValue, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_LOG2E", &pc->FP64Type, (union AnyValue *)&M_LOG2EValue, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_LOG10E", &pc->FP64Type, (union AnyValue *)&M_LOG10EValue, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_LN2", &pc->FP64Type, (union AnyValue *)&M_LN2Value, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_LN10", &pc->FP64Type, (union AnyValue *)&M_LN10Value, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_PI", &pc->FP64Type, (union AnyValue *)&M_PIValue, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_PI_2", &pc->FP64Type, (union AnyValue *)&M_PI_2Value, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_PI_4", &pc->FP64Type, (union AnyValue *)&M_PI_4Value, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_1_PI", &pc->FP64Type, (union AnyValue *)&M_1_PIValue, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_2_PI", &pc->FP64Type, (union AnyValue *)&M_2_PIValue, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_2_SQRTPI", &pc->FP64Type, (union AnyValue *)&M_2_SQRTPIValue, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_SQRT2", &pc->FP64Type, (union AnyValue *)&M_SQRT2Value, FALSE);
    VariableDefinePlatformVar(pc, NULL, "M_SQRT1_2", &pc->FP64Type, (union AnyValue *)&M_SQRT1_2Value, FALSE);
}

#endif /* !NO_FP */
#endif /* !BUILTIN_MINI_STDLIB */
