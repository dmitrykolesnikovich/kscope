#pragma once

#include <string>
#include <vector>

#include "ASTNode.h"


class PrototypeNode : public ASTNode {
public:
  std::string name;
  std::unique_ptr<std::vector<std::string> > args;

  PrototypeNode(const std::string &name,
                std::unique_ptr<std::vector<std::string> > args)
    : name(name), args(std::move(args)) {};

  template<class Result, typename Function> Result* render(Renderer<Result, Function> *renderer) {
    return renderer->render(this);
  };
};
