/***************************************************************************
                          shape_file_parser.h  -  description
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
//	Specifies the classes used to fuzzyfy and defuzzyfy data

#ifndef shape_file_parser_h
#define shape_file_parser_h 1


#include "shapes_list.h"

#ifdef DMALLOC
#include <dmalloc.h>
#endif

/**
* This class is used to read the shape list from files.
* @short read the shapes
*/

class shape_file_parser 
{
 public:
  /**
   * Constructor generated by the UML software used to build Brian. It return an empty shape file parser.
   */
  shape_file_parser();

  /**
   * Copy constructor generated by the UML software used to build Brian. It return a copy of the shape file parser.
   */
  shape_file_parser(const shape_file_parser &right);

  /*
   * Constructor that build a shape file parser that read the shapes from file
   * @param file_name is the name of the file containing the shapes
   */
  shape_file_parser (char *file_name);

  /**	
   * Destructor destroy a shape file parser: free the name of the file.
   */
  ~shape_file_parser();


  /**
   * Method that read the shapes from a file and return a pointer to the shape list. It point to the original list so it must not be destroyed.
   * @return a pointer to a shape list
   */ 
  shapes_list * read_shapelist ();

  /**	
   * Return the name of the file containing the shapes
   * @return a string
   */
  const char * get_name ();
  /**
   * Set the name of the file containing the shapes 
   * @param value is the name of the file
   */
  void set_name (char * value);

 private:
  // Data Members for Class Attributes

  char *name;
};

// Class shape_file_parser 

inline const char * shape_file_parser::get_name ()
{
  return name;
}

inline void shape_file_parser::set_name (char * value)
{
  if (name!=NULL) free(name);
  name = (char *) malloc(strlen(value)+1);
  strcpy(name,value);
}


#endif
