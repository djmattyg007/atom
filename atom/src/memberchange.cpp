/*-----------------------------------------------------------------------------
| Copyright (c) 2013-2017, Nucleic Development Team.
|
| Distributed under the terms of the Modified BSD License.
|
| The full license is in the file COPYING.txt, distributed with this software.
|----------------------------------------------------------------------------*/
#include <cppy/cppy.h>
#include "memberchange.h"


namespace MemberChange
{

static PyObject* createstr;
static PyObject* updatestr;
static PyObject* deletestr;
static PyObject* eventstr;
static PyObject* propertystr;
static PyObject* typestr;
static PyObject* objectstr;
static PyObject* namestr;
static PyObject* valuestr;
static PyObject* oldvaluestr;


PyObject*
created( CAtom* atom, Member* member, PyObject* value )
{
    cppy::ptr dict( PyDict_New() );
    if( !dict )
        return 0;
    if( !dict.setitem( typestr, createstr ) )
        return 0;
    if( !dict.setitem( objectstr, pyobject_cast( atom ) ) )
        return 0;
    if( !dict.setitem( namestr, member->name ) )
        return 0;
    if( !dict.setitem( valuestr, value ) )
        return 0;
    return dict.release();
}


PyObject*
updated( CAtom* atom, Member* member, PyObject* oldvalue, PyObject* newvalue )
{
    cppy::ptr dict( PyDict_New() );
    if( !dict )
        return 0;
    if( !dict.setitem( typestr, updatestr ) )
        return 0;
    if( !dict.setitem( objectstr, pyobject_cast( atom ) ) )
        return 0;
    if( !dict.setitem( namestr, member->name ) )
        return 0;
    if( !dict.setitem( oldvaluestr, oldvalue ) )
        return 0;
    if( !dict.setitem( valuestr, newvalue ) )
        return 0;
    return dict.release();
}


PyObject*
deleted( CAtom* atom, Member* member, PyObject* value )
{
    cppy::ptr dict( PyDict_New() );
    if( !dict )
        return 0;
    if( !dict.setitem( typestr, deletestr ) )
        return 0;
    if( !dict.setitem( objectstr, pyobject_cast( atom ) ) )
        return 0;
    if( !dict.setitem( namestr, member->name ) )
        return 0;
    if( !dict.setitem( valuestr, value ) )
        return 0;
    return dict.release();
}


PyObject*
event( CAtom* atom, Member* member, PyObject* value )
{
    cppy::ptr dict( PyDict_New() );
    if( !dict )
        return 0;
    if( !dict.setitem( typestr, eventstr ) )
        return 0;
    if( !dict.setitem( objectstr, pyobject_cast( atom ) ) )
        return 0;
    if( !dict.setitem( namestr, member->name ) )
        return 0;
    if( !dict.setitem( valuestr, value ) )
        return 0;
    return dict.release();
}


PyObject*
property( CAtom* atom, Member* member, PyObject* oldvalue, PyObject* newvalue )
{
    cppy::ptr dict( PyDict_New() );
    if( !dict )
        return 0;
    if( !dict.setitem( typestr, propertystr ) )
        return 0;
    if( !dict.setitem( objectstr, pyobject_cast( atom ) ) )
        return 0;
    if( !dict.setitem( namestr, member->name ) )
        return 0;
    if( !dict.setitem( oldvaluestr, oldvalue ) )
        return 0;
    if( !dict.setitem( valuestr, newvalue ) )
        return 0;
    return dict.release();
}

} // namespace MemberChange


int
import_memberchange()
{
    static bool alloced = false;
    if( alloced )
        return 0;
    MemberChange::createstr = PyUnicode_InternFromString( "create" );
    if( !MemberChange::createstr )
        return -1;
    MemberChange::updatestr = PyUnicode_InternFromString( "update" );
    if( !MemberChange::updatestr )
        return -1;
    MemberChange::deletestr = PyUnicode_InternFromString( "delete" );
    if( !MemberChange::deletestr )
        return -1;
    MemberChange::eventstr = PyUnicode_InternFromString( "event" );
    if( !MemberChange::eventstr )
        return -1;
    MemberChange::propertystr = PyUnicode_InternFromString( "property" );
    if( !MemberChange::propertystr )
        return -1;
    MemberChange::typestr = PyUnicode_InternFromString( "type" );
    if( !MemberChange::typestr )
        return -1;
    MemberChange::objectstr = PyUnicode_InternFromString( "object" );
    if( !MemberChange::objectstr )
        return -1;
    MemberChange::namestr = PyUnicode_InternFromString( "name" );
    if( !MemberChange::namestr )
        return -1;
    MemberChange::valuestr = PyUnicode_InternFromString( "value" );
    if( !MemberChange::valuestr )
        return -1;
    MemberChange::oldvaluestr = PyUnicode_InternFromString( "oldvalue" );
    if( !MemberChange::oldvaluestr )
        return -1;
    alloced = true;
    return 0;
}
