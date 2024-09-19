#include "second_projApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
second_projApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

second_projApp::second_projApp(InputParameters parameters) : MooseApp(parameters)
{
  second_projApp::registerAll(_factory, _action_factory, _syntax);
}

second_projApp::~second_projApp() {}

void
second_projApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<second_projApp>(f, af, s);
  Registry::registerObjectsTo(f, {"second_projApp"});
  Registry::registerActionsTo(af, {"second_projApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
second_projApp::registerApps()
{
  registerApp(second_projApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
second_projApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  second_projApp::registerAll(f, af, s);
}
extern "C" void
second_projApp__registerApps()
{
  second_projApp::registerApps();
}
