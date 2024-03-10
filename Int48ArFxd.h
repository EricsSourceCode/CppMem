/*

// Copyright Eric Chauvin 2023.



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


#include "../CppBase/BasicTypes.h"
#include "../CppBase/RangeC.h"
#include "../CppBase/Casting.h"
#include "../CppInt/IntConst.h"
#include "../CppInt/Int48.h"


// -Wno-unsafe-buffer-usage

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"


class Int48ArFxd
  {
  private:
  bool testForCopy = false;
  static const Int32 last =
                   IntConst::digitArraySize;
  Int48 Int48Ar[last] = {  };

  public:
  Int48ArFxd( void )
    {
    }


  Int48ArFxd( const Int48ArFxd& in )
    {
    if( in.testForCopy )
      return;

    throw "Int48ArFxd copy constructor.";
    }


  ~Int48ArFxd( void )
    {
    }


  inline Int48& getRef( const Int32 where )
    {
    RangeC::test2( where, 0, last - 1,
      "Int48ArFxd.getRef() size range." );

    return Int48Ar[where];
    }



You can't mark a reference as constant.

  inline Int48& getRefConst(
                     const Int32 where ) const
    {
    RangeC::test2( where, 0, last - 1,
      "Int48ArFxd.getRefConst() size range." );

    return Int48Ar[where];
    }



///////
  inline void setVal( const Int32 where,
                      const Int32 toSet )
    {
    RangeC::test2( where, 0, arraySize - 1,
           "Int32Array.setVal where range." );

    iArray[where] = toSet;
    }


  inline void copy( const Int32Array& in )
    {
    setSize( in.arraySize );

    const Int32 max = arraySize;
    for( Int32 count = 0; count < max; count++ )
      iArray[count] = in.iArray[count];

    }
/////////

  };


#pragma clang diagnostic pop

*/
