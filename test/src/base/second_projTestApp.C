//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "second_projTestApp.h"
#include "second_projApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
second_projTestApp::validParams()
{
  InputParameters params = second_projApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

second_projTestApp::second_projTestApp(InputParameters parameters) : MooseApp(parameters)
{
  second_projTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

second_projTestApp::~second_projTestApp() {}

void
second_projTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  second_projApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"second_projTestApp"});
    Registry::registerActionsTo(af, {"second_projTestApp"});
  }
}

void
second_projTestApp::registerApps()
{
  registerApp(second_projApp);
  registerApp(second_projTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
second_projTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  second_projTestApp::registerAll(f, af, s);
}
extern "C" void
second_projTestApp__registerApps()
{
  second_projTestApp::registerApps();
}
