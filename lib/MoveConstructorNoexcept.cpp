
#include "MoveConstructorNoexcept.h"
#include "clang/AST/Decl.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchersInternal.h"

using namespace clang::ast_matchers;
using namespace clang;

void MoveConstructorNoexcepts::registerMatchers(
    clang::ast_matchers::MatchFinder *Finder) {
  // clang::ast_matchers::DeclarationMatcher
  Finder->addMatcher(functionDecl().bind("x"), this);
}

void MoveConstructorNoexcepts::check(
    const clang::ast_matchers::MatchFinder::MatchResult &Result) {
  const auto *MatchedDecl = Result.Nodes.getNodeAs<FunctionDecl>("x");
  if (!MatchedDecl->getIdentifier() ||
      MatchedDecl->getName().startswith("MoveConstruc"))
    return;
  diag(MatchedDecl->getLocation(), "function %0 is insufficiently awesome")
      << MatchedDecl
      << clang::FixItHint::CreateInsertion(MatchedDecl->getLocation(),
                                           "awesome_");
}
