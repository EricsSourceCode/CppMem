// Copyright Eric Chauvin 2024.



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once


#include "../CppBase/BasicTypes.h"
#include "../CppBase/RangeC.h"
#include "../CppBase/Casting.h"


#include "MemoryWarnTop.h"



class Float32Array
  {
  private:
  bool testForCopy = false;
  Int32 arraySize = 1;
  Float32* fArray;

  public:
  inline Float32Array( void )
    {
    arraySize = 1;
    fArray = new Float32[
                  Casting::i32ToU64( arraySize )];
    }


  inline Float32Array( const Float32Array& in )
    {
    arraySize = 1;
    fArray = new Float32[
               Casting::i32ToU64( arraySize )];

    if( in.testForCopy )
      return;

    throw "Float32Array copy constructor.";
    }


  inline ~Float32Array( void )
    {
    delete[] fArray;
    }

  inline void setSize( const Int32 howBig )
    {
    if( howBig == arraySize )
      return;

    arraySize = howBig;
    delete[] fArray;
    fArray = new Float32[
                 Casting::i32ToU64( arraySize )];
    }


  inline Int32 getSize( void ) const
    {
    return arraySize;
    }

  inline Float32 getVal( 
                     const Int32 where ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
      "Float32Array.getVal arraySize range." );

    return fArray[where];
    }

  inline void setVal( const Int32 where,
                      const Float32 toSet )
    {
    RangeC::test2( where, 0, arraySize - 1,
           "Float32Array.setVal where range." );

    fArray[where] = toSet;
    }


  inline void copy( const Float32Array& in )
    {
    setSize( in.arraySize );

    const Int32 max = arraySize;
    for( Int32 count = 0; count < max; count++ )
      fArray[count] = in.fArray[count];

    }

  };


#include "MemoryWarnBottom.h"
