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



add_executable(exClassMemberDefaultInit exercises/exClassMemberDefaultInit.cpp)
set_target_properties(exClassMemberDefaultInit PROPERTIES
  FOLDER "exClassMemberDefaultInit"
  CXX_STANDARD 11
)

add_executable(exConstexprApply exercises/exConstexprApply.cpp)
set_target_properties(exConstexprApply PROPERTIES
  FOLDER "exConstexprApply"
  CXX_STANDARD 17
)

add_executable(exFlatMap exercises/exFlatMap.cpp)
set_target_properties(exFlatMap PROPERTIES
  FOLDER "exFlatMap"
  CXX_STANDARD 17
)

add_executable(exInitializerList2 exercises/exInitializerList2.cpp)
set_target_properties(exInitializerList2 PROPERTIES
  FOLDER "exInitializerList2"
  CXX_STANDARD 14
)

add_executable(exLambdaCapture exercises/exLambdaCapture.cpp)
set_target_properties(exLambdaCapture PROPERTIES
  FOLDER "exLambdaCapture"
  CXX_STANDARD 17
)

add_executable(exLambdaUB exercises/exLambdaUB.cpp)
set_target_properties(exLambdaUB PROPERTIES
  FOLDER "exLambdaUB"
  CXX_STANDARD 14
)

add_executable(exMemoryAccess exercises/exMemoryAccess.cpp)
set_target_properties(exMemoryAccess PROPERTIES
  FOLDER "exMemoryAccess"
  CXX_STANDARD 20
)

add_executable(exMoveSemantics exercises/exMoveSemantics.cpp)
set_target_properties(exMoveSemantics PROPERTIES
  FOLDER "exMoveSemantics"
  CXX_STANDARD 14
)

add_executable(exRangeBasedForLoop exercises/exRangeBasedForLoop.cpp)
set_target_properties(exRangeBasedForLoop PROPERTIES
  FOLDER "exRangeBasedForLoop"
  CXX_STANDARD 14
)

add_executable(exSharedPtrSize exercises/exSharedPtrSize.cpp)
set_target_properties(exSharedPtrSize PROPERTIES
  FOLDER "exSharedPtrSize"
  CXX_STANDARD 11
)

add_executable(exSimpleList exercises/exSimpleList.cpp)
set_target_properties(exSimpleList PROPERTIES
  FOLDER "exSimpleList"
  CXX_STANDARD 14
)

add_executable(exUniformInit exercises/exUniformInit.cpp)
set_target_properties(exUniformInit PROPERTIES
  FOLDER "exUniformInit"
  CXX_STANDARD 11
)

add_executable(exUniformInit2 exercises/exUniformInit2.cpp)
set_target_properties(exUniformInit2 PROPERTIES
  FOLDER "exUniformInit2"
  CXX_STANDARD 14
)

add_executable(exUniquePtrCosts exercises/exUniquePtrCosts.cpp)
set_target_properties(exUniquePtrCosts PROPERTIES
  FOLDER "exUniquePtrCosts"
  CXX_STANDARD 17
)

add_executable(exUniquePtrWithCustomDeleter exercises/exUniquePtrWithCustomDeleter.cpp)
set_target_properties(exUniquePtrWithCustomDeleter PROPERTIES
  FOLDER "exUniquePtrWithCustomDeleter"
  CXX_STANDARD 11
)

add_executable(exVariadicTemplateSum exercises/exVariadicTemplateSum.cpp)
set_target_properties(exVariadicTemplateSum PROPERTIES
  FOLDER "exVariadicTemplateSum"
  CXX_STANDARD 17
)

add_executable(exVariadicTemplateSumSameType exercises/exVariadicTemplateSumSameType.cpp)
set_target_properties(exVariadicTemplateSumSameType PROPERTIES
  FOLDER "exVariadicTemplateSumSameType"
  CXX_STANDARD 17
)

add_executable(solClassMemberDefaultInit solutions/solClassMemberDefaultInit.cpp)
set_target_properties(solClassMemberDefaultInit PROPERTIES
  FOLDER "solClassMemberDefaultInit"
  CXX_STANDARD 11
)

add_executable(solConstexprApply solutions/solConstexprApply.cpp)
set_target_properties(solConstexprApply PROPERTIES
  FOLDER "solConstexprApply"
  CXX_STANDARD 17
)

add_executable(solCtorInheritance solutions/solCtorInheritance.cpp)
set_target_properties(solCtorInheritance PROPERTIES
  FOLDER "solCtorInheritance"
  CXX_STANDARD 11
)

add_executable(solFlatMap solutions/solFlatMap.cpp)
set_target_properties(solFlatMap PROPERTIES
  FOLDER "solFlatMap"
  CXX_STANDARD 17
)

add_executable(solInitializerList2 solutions/solInitializerList2.cpp)
set_target_properties(solInitializerList2 PROPERTIES
  FOLDER "solInitializerList2"
  CXX_STANDARD 11
)

add_executable(solInitializerList3 solutions/solInitializerList3.cpp)
set_target_properties(solInitializerList3 PROPERTIES
  FOLDER "solInitializerList3"
  CXX_STANDARD 11
)

add_executable(solLambdaCapture solutions/solLambdaCapture.cpp)
set_target_properties(solLambdaCapture PROPERTIES
  FOLDER "solLambdaCapture"
  CXX_STANDARD 17
)

add_executable(solLambdaUB solutions/solLambdaUB.cpp)
set_target_properties(solLambdaUB PROPERTIES
  FOLDER "solLambdaUB"
  CXX_STANDARD 14
)

add_executable(solMoveSemantics solutions/solMoveSemantics.cpp)
set_target_properties(solMoveSemantics PROPERTIES
  FOLDER "solMoveSemantics"
  CXX_STANDARD 14
)

add_executable(solRangeBasedForLoop solutions/solRangeBasedForLoop.cpp)
set_target_properties(solRangeBasedForLoop PROPERTIES
  FOLDER "solRangeBasedForLoop"
  CXX_STANDARD 14
)

add_executable(solSharedPtrSize solutions/solSharedPtrSize.cpp)
set_target_properties(solSharedPtrSize PROPERTIES
  FOLDER "solSharedPtrSize"
  CXX_STANDARD 17
)

add_executable(solSimpleList solutions/solSimpleList.cpp)
set_target_properties(solSimpleList PROPERTIES
  FOLDER "solSimpleList"
  CXX_STANDARD 17
)

add_executable(solTypeTraitsAssert solutions/solTypeTraitsAssert.cpp)
set_target_properties(solTypeTraitsAssert PROPERTIES
  FOLDER "solTypeTraitsAssert"
  CXX_STANDARD 17
)

add_executable(solUniformInit solutions/solUniformInit.cpp)
set_target_properties(solUniformInit PROPERTIES
  FOLDER "solUniformInit"
  CXX_STANDARD 11
)

add_executable(solUniformInit2 solutions/solUniformInit2.cpp)
set_target_properties(solUniformInit2 PROPERTIES
  FOLDER "solUniformInit2"
  CXX_STANDARD 11
)

add_executable(solUniquePtr solutions/solUniquePtr.cpp)
set_target_properties(solUniquePtr PROPERTIES
  FOLDER "solUniquePtr"
  CXX_STANDARD 14
)

add_executable(solUniquePtrCosts solutions/solUniquePtrCosts.cpp)
set_target_properties(solUniquePtrCosts PROPERTIES
  FOLDER "solUniquePtrCosts"
  CXX_STANDARD 17
)

add_executable(solUniquePtrWithCustomDeleter solutions/solUniquePtrWithCustomDeleter.cpp)
set_target_properties(solUniquePtrWithCustomDeleter PROPERTIES
  FOLDER "solUniquePtrWithCustomDeleter"
  CXX_STANDARD 11
)

add_executable(solUniquePtrWithCustomDeleterEfficient solutions/solUniquePtrWithCustomDeleterEfficient.cpp)
set_target_properties(solUniquePtrWithCustomDeleterEfficient PROPERTIES
  FOLDER "solUniquePtrWithCustomDeleterEfficient"
  CXX_STANDARD 17
)

add_executable(solVariadicTemplateSum solutions/solVariadicTemplateSum.cpp)
set_target_properties(solVariadicTemplateSum PROPERTIES
  FOLDER "solVariadicTemplateSum"
  CXX_STANDARD 17
)

add_executable(solVariadicTemplateSumConstexpr solutions/solVariadicTemplateSumConstexpr.cpp)
set_target_properties(solVariadicTemplateSumConstexpr PROPERTIES
  FOLDER "solVariadicTemplateSumConstexpr"
  CXX_STANDARD 11
)

add_executable(solVariadicTemplateSumSameType solutions/solVariadicTemplateSumSameType.cpp)
set_target_properties(solVariadicTemplateSumSameType PROPERTIES
  FOLDER "solVariadicTemplateSumSameType"
  CXX_STANDARD 17
)

