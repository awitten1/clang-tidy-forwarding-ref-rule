
#pragma once

#include <clang-tidy/ClangTidyCheck.h>

namespace MyClangCheck {

class MoveConstructorNoexcepts : public clang::tidy::ClangTidyCheck {
 public:

  MoveConstructorNoexcepts(clang::StringRef Name,
                           clang::tidy::ClangTidyContext* Context)
      : clang::tidy::ClangTidyCheck(Name, Context) {}

  void registerMatchers(clang::ast_matchers::MatchFinder* Finder) override;

  void check(
      const clang::ast_matchers::MatchFinder::MatchResult& Result) override;
};

}  // namespace MyClangCheck
