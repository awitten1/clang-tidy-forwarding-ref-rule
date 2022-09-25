
#include "MoveConstructorNoexcept.h"

using namespace clang::ast_matchers;
using namespace clang;

void MoveConstructorNoexcepts::registerMatchers(
    clang::ast_matchers::MatchFinder *Finder) {
  Finder->addMatcher(cxxConstructorDecl().bind("x"), this);
}

void MoveConstructorNoexcepts::check(
    const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  const auto *MatchedDecl = Result.Nodes.getNodeAs<CXXConstructorDecl>("x");
  if (!MatchedDecl->isMoveConstructor()) {
    return;
  }
  if (MatchedDecl->getExceptionSpecType() == EST_None) {
    diag(MatchedDecl->getLocation(), "move constructor %0 not marked noexcept")
        << MatchedDecl;
  }
}
