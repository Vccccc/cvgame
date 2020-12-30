#include "gui/PropertyHelper.h"
#include "gui/TypedProperty.h"
#include <iostream>
#include <cassert>
using namespace std;

void testPropertyHelper()
{
    PropertyHelper<int> intHelper;
    PropertyHelper<string> strHelper;
    PropertyHelper<bool> boolHelper;

    cout << intHelper.getDataTypeName() << endl;
    assert(100 == intHelper.fromString("100"));
    cout << "toString: " << intHelper.toString(100) << endl;

    cout << strHelper.getDataTypeName() << endl;
    assert("100" == strHelper.fromString("100"));
    cout << "toString: " << strHelper.toString("100") << endl;

    cout << intHelper.getDataTypeName() << endl;
    assert(true == boolHelper.fromString("true"));
    cout << "toString: " << boolHelper.toString(true) << endl;
}


void testTypedProperty()
{
    TypedProperty<int> intProperty("int", "100");
    TypedProperty<string> stringProperty("string", "this is string");
    TypedProperty<bool> boolProperty("bool", "true");

    cout << intProperty.getName() << endl;
    cout << intProperty.getDataType() << endl;

    cout << stringProperty.getName() << endl;
    cout << stringProperty.getDataType() << endl;

    cout << boolProperty.getName() << endl;
    cout << boolProperty.getDataType() << endl;

    TypedProperty<const int> constIntProperty("int", "100");
    cout << constIntProperty.getName() << endl;
    cout << constIntProperty.getDataType() << endl;
}
int main()
{
    testTypedProperty();
    bool b();
    return 0;
}