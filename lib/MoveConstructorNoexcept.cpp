
#include "MoveConstructorNoexcept.h"

void MyClangCheck::MoveConstructorNoexcepts::registerMatchers(
    clang::ast_matchers::MatchFinder* Finder) {}

void MyClangCheck::MoveConstructorNoexcepts::check(
    const clang::ast_matchers::MatchFinder::MatchResult& Result) {}
