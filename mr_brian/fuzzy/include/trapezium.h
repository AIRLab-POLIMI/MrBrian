/***************************************************************************
                          trapezium.h  -  description
                             -------------------
    begin                : Wed Sep 13 2000
    copyright            : (C) 2000 by Halva Giovanni & Giacomo
    email                : invehalv@airlab.elet.polimi.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/




#ifndef trapezium_h
#define trapezium_h 1

#include "fuzzy_set.h"

#ifdef DMALLOC

#include <dmalloc.h>

#endif


/**
* This class inherits from fuzzy_set and specifies it to be a trapezium.
* @short Class implementing the concept of trapezium fuzzy set.
*/

class trapezium : public fuzzy_set  //## Inherits: trapezium_inheritance%382BDE1E02EE
{
 public:
  /**
   * Constructor generated by the UML software used to build Brian. It return an empty trapetium.
   */
  trapezium();

  /**
   * Copy constructor generated by the UML software used to build Brian. It return a copy of the fuzzy set passed.
   */      
  trapezium(const trapezium &right);

  /**	
   * Constructor that build a trapetium.
   * @param alabel is the label given to the the fuzzy set
   * @param aa is the first point of the fuzzy set
   * @param ab is the second point of the fuzzy set
   * @param ac is the third point of the fuzzy set
   * @param ad is the fourth point of the fuzzy set
   */
  trapezium (char* alabel, float aa, float ab, float ac, float ad);

  /**	
   * Destructor destroy a fuzzy set and free its data.
   */
  virtual ~trapezium();

  /**	
   * Return the first point of the fuzzy set.
   * @return the value of the first point
   */
  float get_a ();
  /**
   * Modify the value of the first point of the fuzzy set.
   * @param value the new value of the point
   */
  void set_a (float value);

  /**	
   * Return the second point of the fuzzy set.
   * @return the value of the first point
   */
  float get_c ();
  /**
   * Modify the value of the second point of the fuzzy set.
   * @param value the new value of the point
   */
  void set_c (float value);

  /**	
   * Return the third point of the fuzzy set.
   * @return the value of the third point
   */
 float get_b ();
  /**
   * Modify the value of the fourth point of the fuzzy set.
   * @param value the new value of the point
   */  
  void set_b (float value);

  /**	
   * Return the fourth point of the fuzzy set.
   * @return the value of the fourth point
   */
  float get_d ();
  /**
   * Modify the value of the fourth point of the fuzzy set.
   * @param value the new value of the point
   */
  void set_d (float value);
  
  /**	
   * Return the membership of data to the fuzzy set.
   * @see fuzzy_set
   * @return the membership value
   * @param avalue is a crisp data
   */
  float get_membership_value(float avalue);

 private:
  // Data Members for Class Attributes

  float a;

  float b;

  float c;

  float d;
};


// Class trapezium 

inline float trapezium::get_a ()
{
  return a;
}

inline void trapezium::set_a (float value)
{
  a = value;
}

inline float trapezium::get_c ()
{
  return c;
}

inline void trapezium::set_c (float value)
{
  c = value;
}

inline float trapezium::get_b ()
{
  return b;
}

inline void trapezium::set_b (float value)
{
  b = value;
}

inline float trapezium::get_d ()
{
  return d;
}

inline void trapezium::set_d (float value)
{
  d = value;
}


#endif
