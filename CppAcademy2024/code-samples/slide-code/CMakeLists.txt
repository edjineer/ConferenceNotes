#==================================================================================================
#
#  Copyright (C) Andreas Fertig - All Rights Reserved
#
#  This file is part of the C++ training by Andreas Fertig. The file may only be used in the
#  context of the C++ training or with explicit agreement by Andreas Fertig.
#
#==================================================================================================

cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
project("Modern C++: When Efficiency Matters" CXX)

# use solution folders in Visual Studio/CLion
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON) # Yes, we require this standard
set(CMAKE_CXX_EXTENSIONS OFF)       # Pure C++ please


if(MSVC)
    # Use sane and nice C++ for MSVC.
    # This makes alternative tokens (not, and, ...) as actual keywords and
    # enables more conforming C++ in general
    add_definitions(/permissive-)

    
else()
    

    if(IS_CLANG)
        add_definitions(-fexperimental-library) # std::format for Clang 15 and 16 at least
        
    else()
    endif()
endif()


enable_testing()



add_executable(appendAndRefQualifiers0 appendAndRefQualifiers0.cpp)
set_target_properties(appendAndRefQualifiers0 PROPERTIES
  FOLDER "appendAndRefQualifiers0"
  CXX_STANDARD 17
)

add_executable(appendAndRefQualifiers1 appendAndRefQualifiers1.cpp)
set_target_properties(appendAndRefQualifiers1 PROPERTIES
  FOLDER "appendAndRefQualifiers1"
  CXX_STANDARD 17
)

add_executable(bracedInit0 bracedInit0.cpp)
set_target_properties(bracedInit0 PROPERTIES
  FOLDER "bracedInit0"
  CXX_STANDARD 17
)

add_executable(bracedInit1 bracedInit1.cpp)
set_target_properties(bracedInit1 PROPERTIES
  FOLDER "bracedInit1"
  CXX_STANDARD 17
)

add_executable(comparisonRecursionVsFoldExpression0 comparisonRecursionVsFoldExpression0.cpp)
set_target_properties(comparisonRecursionVsFoldExpression0 PROPERTIES
  FOLDER "comparisonRecursionVsFoldExpression0"
  CXX_STANDARD 20
)

add_executable(comparisonRecursionVsFoldExpression1 comparisonRecursionVsFoldExpression1.cpp)
set_target_properties(comparisonRecursionVsFoldExpression1 PROPERTIES
  FOLDER "comparisonRecursionVsFoldExpression1"
  CXX_STANDARD 20
)

add_executable(comparisonRecursionVsFoldExpression2 comparisonRecursionVsFoldExpression2.cpp)
set_target_properties(comparisonRecursionVsFoldExpression2 PROPERTIES
  FOLDER "comparisonRecursionVsFoldExpression2"
  CXX_STANDARD 20
)

add_executable(correctForward0 correctForward0.cpp)
set_target_properties(correctForward0 PROPERTIES
  FOLDER "correctForward0"
  CXX_STANDARD 20
)

add_executable(ctad0 ctad0.cpp)
set_target_properties(ctad0 PROPERTIES
  FOLDER "ctad0"
  CXX_STANDARD 20
)

add_executable(ctadOrMakeFunctions0 ctadOrMakeFunctions0.cpp)
set_target_properties(ctadOrMakeFunctions0 PROPERTIES
  FOLDER "ctadOrMakeFunctions0"
  CXX_STANDARD 17
)

add_executable(ctorInheritance0 ctorInheritance0.cpp)
set_target_properties(ctorInheritance0 PROPERTIES
  FOLDER "ctorInheritance0"
  CXX_STANDARD 20
)

add_executable(defaultMemberInit0 defaultMemberInit0.cpp)
set_target_properties(defaultMemberInit0 PROPERTIES
  FOLDER "defaultMemberInit0"
  CXX_STANDARD 11
)

add_executable(defaultedDtorAndMove0 defaultedDtorAndMove0.cpp)
set_target_properties(defaultedDtorAndMove0 PROPERTIES
  FOLDER "defaultedDtorAndMove0"
  CXX_STANDARD 20
)

add_executable(demoInsights0 demoInsights0.cpp)
set_target_properties(demoInsights0 PROPERTIES
  FOLDER "demoInsights0"
  CXX_STANDARD 20
)

add_executable(final1 final1.cpp)
set_target_properties(final1 PROPERTIES
  FOLDER "final1"
  CXX_STANDARD 20
)

add_executable(final5 final5.cpp)
set_target_properties(final5 PROPERTIES
  FOLDER "final5"
  CXX_STANDARD 17
)

add_executable(foldExpression0 foldExpression0.cpp)
set_target_properties(foldExpression0 PROPERTIES
  FOLDER "foldExpression0"
  CXX_STANDARD 17
)

add_executable(foldExpression1 foldExpression1.cpp)
set_target_properties(foldExpression1 PROPERTIES
  FOLDER "foldExpression1"
  CXX_STANDARD 17
)

add_executable(forLoop0 forLoop0.cpp)
set_target_properties(forLoop0 PROPERTIES
  FOLDER "forLoop0"
  CXX_STANDARD 11
)

add_executable(foreach0 foreach0.cpp)
set_target_properties(foreach0 PROPERTIES
  FOLDER "foreach0"
  CXX_STANDARD 20
)

add_executable(foreach5 foreach5.cpp)
set_target_properties(foreach5 PROPERTIES
  FOLDER "foreach5"
  CXX_STANDARD 11
)

add_executable(genericLambdas0 genericLambdas0.cpp)
set_target_properties(genericLambdas0 PROPERTIES
  FOLDER "genericLambdas0"
  CXX_STANDARD 14
)

add_executable(ifSwitchInit0 ifSwitchInit0.cpp)
set_target_properties(ifSwitchInit0 PROPERTIES
  FOLDER "ifSwitchInit0"
  CXX_STANDARD 20
)

add_executable(integralConstant0 integralConstant0.cpp)
set_target_properties(integralConstant0 PROPERTIES
  FOLDER "integralConstant0"
  CXX_STANDARD 20
)

add_executable(lambda7 lambda7.cpp)
set_target_properties(lambda7 PROPERTIES
  FOLDER "lambda7"
  CXX_STANDARD 20
)

add_executable(lambdaUse0 lambdaUse0.cpp)
set_target_properties(lambdaUse0 PROPERTIES
  FOLDER "lambdaUse0"
  CXX_STANDARD 20
)

add_executable(lambdaUse1 lambdaUse1.cpp)
set_target_properties(lambdaUse1 PROPERTIES
  FOLDER "lambdaUse1"
  CXX_STANDARD 20
)

add_executable(lambdaVariants0 lambdaVariants0.cpp)
set_target_properties(lambdaVariants0 PROPERTIES
  FOLDER "lambdaVariants0"
  CXX_STANDARD 20
)

add_executable(moveAndVirtual0 moveAndVirtual0.cpp)
set_target_properties(moveAndVirtual0 PROPERTIES
  FOLDER "moveAndVirtual0"
  CXX_STANDARD 20
)

add_executable(moveAndVirtual1 moveAndVirtual1.cpp)
set_target_properties(moveAndVirtual1 PROPERTIES
  FOLDER "moveAndVirtual1"
  CXX_STANDARD 20
)

add_executable(moveSemantics0 moveSemantics0.cpp)
set_target_properties(moveSemantics0 PROPERTIES
  FOLDER "moveSemantics0"
  CXX_STANDARD 17
)

add_executable(moveVsCopy0 moveVsCopy0.cpp)
set_target_properties(moveVsCopy0 PROPERTIES
  FOLDER "moveVsCopy0"
  CXX_STANDARD 20
)

add_executable(moveVsCopy1 moveVsCopy1.cpp)
set_target_properties(moveVsCopy1 PROPERTIES
  FOLDER "moveVsCopy1"
  CXX_STANDARD 20
)

add_executable(noexcept2 noexcept2.cpp)
set_target_properties(noexcept2 PROPERTIES
  FOLDER "noexcept2"
  CXX_STANDARD 20
)

add_executable(noexcept3 noexcept3.cpp)
set_target_properties(noexcept3 PROPERTIES
  FOLDER "noexcept3"
  CXX_STANDARD 20
)

add_executable(noexcept4 noexcept4.cpp)
set_target_properties(noexcept4 PROPERTIES
  FOLDER "noexcept4"
  CXX_STANDARD 20
)

add_executable(pushBackVsEmplaceBack1 pushBackVsEmplaceBack1.cpp)
set_target_properties(pushBackVsEmplaceBack1 PROPERTIES
  FOLDER "pushBackVsEmplaceBack1"
  CXX_STANDARD 20
)

add_executable(reserveIfPossible0 reserveIfPossible0.cpp)
set_target_properties(reserveIfPossible0 PROPERTIES
  FOLDER "reserveIfPossible0"
  CXX_STANDARD 20
)

add_executable(reserveIfPossible1 reserveIfPossible1.cpp)
set_target_properties(reserveIfPossible1 PROPERTIES
  FOLDER "reserveIfPossible1"
  CXX_STANDARD 20
)

add_executable(sharedPtr3 sharedPtr3.cpp)
set_target_properties(sharedPtr3 PROPERTIES
  FOLDER "sharedPtr3"
  CXX_STANDARD 20
)

add_executable(sharedPtr4 sharedPtr4.cpp)
set_target_properties(sharedPtr4 PROPERTIES
  FOLDER "sharedPtr4"
  CXX_STANDARD 20
)

add_executable(sharedPtrImpl0 sharedPtrImpl0.cpp)
set_target_properties(sharedPtrImpl0 PROPERTIES
  FOLDER "sharedPtrImpl0"
  CXX_STANDARD 20
)

add_executable(singleton1 singleton1.cpp)
set_target_properties(singleton1 PROPERTIES
  FOLDER "singleton1"
  CXX_STANDARD 20
)

add_executable(singleton4 singleton4.cpp)
set_target_properties(singleton4 PROPERTIES
  FOLDER "singleton4"
  CXX_STANDARD 20
)

add_executable(static0 static0.cpp)
set_target_properties(static0 PROPERTIES
  FOLDER "static0"
  CXX_STANDARD 20
)

add_executable(staticVsInline0 staticVsInline0.cpp)
set_target_properties(staticVsInline0 PROPERTIES
  FOLDER "staticVsInline0"
  CXX_STANDARD 20
)

add_executable(stdVectorAndNoexcept0 stdVectorAndNoexcept0.cpp)
set_target_properties(stdVectorAndNoexcept0 PROPERTIES
  FOLDER "stdVectorAndNoexcept0"
  CXX_STANDARD 11
)

add_executable(stdVectorAndNoexcept1 stdVectorAndNoexcept1.cpp)
set_target_properties(stdVectorAndNoexcept1 PROPERTIES
  FOLDER "stdVectorAndNoexcept1"
  CXX_STANDARD 11
)

add_executable(strCat0 strCat0.cpp)
set_target_properties(strCat0 PROPERTIES
  FOLDER "strCat0"
  CXX_STANDARD 17
)

add_executable(templatesTypeOnly0 templatesTypeOnly0.cpp)
set_target_properties(templatesTypeOnly0 PROPERTIES
  FOLDER "templatesTypeOnly0"
  CXX_STANDARD 20
)

add_executable(templatesTypeOnly1 templatesTypeOnly1.cpp)
set_target_properties(templatesTypeOnly1 PROPERTIES
  FOLDER "templatesTypeOnly1"
  CXX_STANDARD 20
)

add_executable(typeTraitsIsPointer0 typeTraitsIsPointer0.cpp)
set_target_properties(typeTraitsIsPointer0 PROPERTIES
  FOLDER "typeTraitsIsPointer0"
  CXX_STANDARD 20
)

add_executable(uniformInit0 uniformInit0.cpp)
set_target_properties(uniformInit0 PROPERTIES
  FOLDER "uniformInit0"
  CXX_STANDARD 11
)

add_executable(uniformInit1 uniformInit1.cpp)
set_target_properties(uniformInit1 PROPERTIES
  FOLDER "uniformInit1"
  CXX_STANDARD 11
)

add_executable(uniformInit2 uniformInit2.cpp)
set_target_properties(uniformInit2 PROPERTIES
  FOLDER "uniformInit2"
  CXX_STANDARD 11
)

add_executable(uniformInit3 uniformInit3.cpp)
set_target_properties(uniformInit3 PROPERTIES
  FOLDER "uniformInit3"
  CXX_STANDARD 11
)

add_executable(uniformInit4 uniformInit4.cpp)
set_target_properties(uniformInit4 PROPERTIES
  FOLDER "uniformInit4"
  CXX_STANDARD 11
)

add_executable(uniformInit5 uniformInit5.cpp)
set_target_properties(uniformInit5 PROPERTIES
  FOLDER "uniformInit5"
  CXX_STANDARD 11
)

add_executable(uniquePtr0 uniquePtr0.cpp)
set_target_properties(uniquePtr0 PROPERTIES
  FOLDER "uniquePtr0"
  CXX_STANDARD 11
)

add_executable(uniquePtr1 uniquePtr1.cpp)
set_target_properties(uniquePtr1 PROPERTIES
  FOLDER "uniquePtr1"
  CXX_STANDARD 14
)

add_executable(uref0 uref0.cpp)
set_target_properties(uref0 PROPERTIES
  FOLDER "uref0"
  CXX_STANDARD 11
)

add_executable(useConstexprIfInsteadOfEnableIf0 useConstexprIfInsteadOfEnableIf0.cpp)
set_target_properties(useConstexprIfInsteadOfEnableIf0 PROPERTIES
  FOLDER "useConstexprIfInsteadOfEnableIf0"
  CXX_STANDARD 20
)

add_executable(useConstexprIfInsteadOfEnableIf1 useConstexprIfInsteadOfEnableIf1.cpp)
set_target_properties(useConstexprIfInsteadOfEnableIf1 PROPERTIES
  FOLDER "useConstexprIfInsteadOfEnableIf1"
  CXX_STANDARD 20
)

add_executable(usingAndConstructors0 usingAndConstructors0.cpp)
set_target_properties(usingAndConstructors0 PROPERTIES
  FOLDER "usingAndConstructors0"
  CXX_STANDARD 11
)

add_executable(variableTmplOverStructs0 variableTmplOverStructs0.cpp)
set_target_properties(variableTmplOverStructs0 PROPERTIES
  FOLDER "variableTmplOverStructs0"
  CXX_STANDARD 14
)

add_executable(variableTmplOverStructs1 variableTmplOverStructs1.cpp)
set_target_properties(variableTmplOverStructs1 PROPERTIES
  FOLDER "variableTmplOverStructs1"
  CXX_STANDARD 17
)

add_executable(variadicTemplateMultiMin0 variadicTemplateMultiMin0.cpp)
set_target_properties(variadicTemplateMultiMin0 PROPERTIES
  FOLDER "variadicTemplateMultiMin0"
  CXX_STANDARD 17
)

add_executable(weakPtr0 weakPtr0.cpp)
set_target_properties(weakPtr0 PROPERTIES
  FOLDER "weakPtr0"
  CXX_STANDARD 11
)

add_executable(weakPtr1 weakPtr1.cpp)
set_target_properties(weakPtr1 PROPERTIES
  FOLDER "weakPtr1"
  CXX_STANDARD 11
)

