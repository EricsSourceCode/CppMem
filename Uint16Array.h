// Copyright Eric Chauvin 2022 - 2024.



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once



#include "../CppBase/BasicTypes.h"
#include "../CppBase/RangeC.h"
#include "../CppBase/Casting.h"



#include "MemoryWarnTop.h"



class Uint16Array
  {
  private:
  Uint16* cArray;
  Int32 arraySize = 1;
  bool testForCopy = false;

  public:
  Uint16Array( void )
    {
    arraySize = 1;
    cArray = new Uint16[
                  Casting::i32ToU64( arraySize )];
    }

  Uint16Array( const Uint16Array &in )
    {
    arraySize = 1;
    cArray = new Uint16[
                  Casting::i32ToU64( arraySize )];

    if( in.testForCopy )
      return;

    throw "Uint16Array copy constructor";
    }


  ~Uint16Array( void )
    {
    delete[] cArray;
    }

  void setSize( Int32 howBig )
    {
    if( arraySize == howBig )
      return;

    arraySize = howBig;
    delete[] cArray;
    cArray = new Uint16[
                  Casting::i32ToU64( arraySize )];

    }

  inline Int32 getSize( void ) const
    {
    return arraySize;
    }

  inline Uint16 getVal( const Int32 where ) const
    {
    RangeC::test2( where, 0, arraySize - 1,
                  "Uint16Array.getVal() range." );

    return cArray[where];
    }

  inline void setVal( const Int32 where,
                      const Uint16 setTo )
    {
    RangeC::test2( where, 0, arraySize - 1,
                  "Uint16Array.setVal() range." );

    cArray[where] = setTo;
    }




  void increaseSize( const Int32 howMuch )
    {
    if( howMuch < 1 )
      throw
       "Uint16Array.increaseSize() howMuch.";

    if( ( Casting::i32ToU64( arraySize ) +
          Casting::i32ToU64( howMuch ) ) >=
        0x7FFFFFFF )
      throw "Uint16Array.increaseSize too big.";

    const Int32 max = arraySize;
    arraySize = arraySize + howMuch;

    Uint16* tempArray = new
          Uint16[Casting::i32ToU64( arraySize )];

    for( Int32 count = 0; count < max; count++ )
      tempArray[count] = cArray[count];

    delete[] cArray;

    // Assign the pointer to the new array.
    cArray = tempArray;
    }


  void copy( const Uint16Array& copyFrom,
                   const Int32 howMany,
                   const Int32 setToSize )
    {
    if( setToSize < howMany )
      throw
        "Uint16Array.copy() setToSize < howMany";

    const Int32 thisSize = getSize();
    if( thisSize != setToSize )
      setSize( setToSize );

    const Int32 fromSize = copyFrom.getSize();
    if( fromSize < howMany )
      throw
       "Uint16Array.copy() fromSize < howMany";

    // memcpy() in string.h.
    // std::memcpy()

    // Use inline assembly to copy a block
    // of memory.

    for( Int32 count = 0; count < howMany;
                                      count++ )
      cArray[count] = copyFrom.cArray[count];

    }

  };



#include "MemoryWarnBottom.h"
