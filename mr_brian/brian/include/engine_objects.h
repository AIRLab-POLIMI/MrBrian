/***************************************************************************
                          engine_objects.h  -  description
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

//	Description: This module contain abstract objects those
//	are used in the other engine module, such as Predicate,
//	Cando and Want Maker. The most important abstract
//	objectis the tree of operations.
//
//	NB predicate_list !!!!!!!!!!!!!!!!!!!!!!!!
//------------------------------------------------------------------------

#ifndef engine_objects_h
#define engine_objects_h 1

#include <malloc.h>

#include <string.h>
#include "interf_obj.h"

#ifdef DMALLOC
#include <dmalloc.h>
#endif


/**      
* The operation class is the father class of all the operators implemented in Brian used to build predicates. It defines the common methods of all the operators
* @short Abstract class implementing the concept of operator.
*/

class operation
{
 public:
  /**
   * Constructor generated by the UML software used to build Brian. It return an empty operation.
   */
  operation();

  /**
   * Copy constructor generated by the UML software used to build Brian. It return a copy of the operation passed.
   */
  operation(const operation &right);

  /**	
   * Destructor destroy an operation
   */
  virtual ~operation();

  /**	
   * Return the value of a structure, it is virtual because the method depends by the type of operation.
   * @return the value of the structure
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */
  virtual float get_value(predicate_list *p, fuzzy_data_list *f)=0;
  /**	
   * Return the reliability of a structure, it is virtual because the method depends by the type of operation.
   * @return the value of the structure
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */
  virtual float get_reliability(predicate_list *p, fuzzy_data_list *f)=0;
      
};


/**
* This class inherits from operation and specifies it to be a NOT operator.
* @short not operator
*/

class op_not : public operation 
{

 public:
  /**	
   * Constructor that build a NOT operator
   * @param apTerm is the pointer to a structure we want to deny 
   */
  op_not(operation * apTerm);

  /**
   * Copy constructor generated by the UML software used to build Brian. It return a copy of the NOT passed.
   */
  op_not(const op_not &right);
      
  /**	
   * Destructor destroy a NOT
   */
  virtual ~op_not();

  /**	
   * Return the poniter to the denied structure  
   * @return a pointer to an operation
   */      
  operation * get_pTerm ();
  /**
   * Modify the poniter to the denied structure
   * @param value is the new structure we want to deny
   */          
  void set_pTerm (operation * value);
    
  /**	
   * Return the value of the structure pointed by the operator. It is one minus the value of the pointed structure.
   * @see operation
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */  
  float get_value(predicate_list *p, fuzzy_data_list *f);
  /**	
   * Return the reliability of the structure pointed by the operator. It is the same of the reliability of the pointed structure.
   * @see operation
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */  
  float get_reliability(predicate_list *p, fuzzy_data_list *f);
      
 private:

  operation *pTerm;
      
};


/**
* This class inherits from operation and specifies it to be an AND operator.
* @short and operator
*/

class op_and : public operation  
{

 public:
  /**	
   * Constructor that build an AND operator
   * @param apTerm_1 is the pointer to the left part of the AND
   * @param apTerm_1 is the pointer to the right part of the AND
   */
  op_and(operation * apTerm_1,operation * apTerm_2);

  /**
   * Copy constructor generated by the UML software used to build Brian. It return a copy of the AND passed.
   */
  op_and(const op_and &right);

  /**	
   * Destructor destroy an AND
   */
  virtual ~op_and();

  /**	
   * Return the poniter to the left part of the AND
   * @return a pointer to an operation
   */     
  operation * get_pTerm_1 ();
    /**	
   * Return the poniter to the right part of the AND
   * @return a pointer to an operation
   */  
  operation * get_pTerm_2 ();

  /**
   * Modify the poniter to the left part of the AND
   * @param value is the new structure we want to put in the AND
   */        
  void set_pTerm_1 (operation * value);
    /**
   * Modify the poniter to the right part of the AND
   * @param value is the new structure we want to put in the AND
   */ 
  void set_pTerm_2 (operation * value);

  /**	
   * Return the value of the structure pointed by the operator. It is the minimum between the value of the two pointed structure.
   * @see operation
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */  
  float get_value(predicate_list *p, fuzzy_data_list *f);
  /**	
   * Return the reliability of the structure pointed by the operator. It is the minimum between the reliability of the two pointed structure. 
   * @see operation
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */  
  float get_reliability(predicate_list *p, fuzzy_data_list *f);

 private:

  operation *pTerm_1;
  operation *pTerm_2;

};


/**
* This class inherits from operation and specifies it to be a OR operator.
* @short or operation
*/

class op_or : public operation 
{

 public:
  /**	
   * Constructor that build an OR operator
   * @param apTerm_1 is the pointer to the left part of the OR
   * @param apTerm_1 is the pointer to the right part of the OR
   */
  op_or(operation * apTerm_1,operation * apTerm_2);

  /**
   * Copy constructor generated by the UML software used to build Brian. It return a copy of the OR passed.
   */
  op_or(const op_or &right);

  /**	
   * Destructor destroy a OR
   */
  virtual ~op_or();

  /**	
   * Return the poniter to the left part of the OR
   * @return a pointer to an operation
   */    
  operation * get_pTerm_1 ();
  /**	
   * Return the poniter to the right part of the OR
   * @return a pointer to an operation
   */  
  operation * get_pTerm_2 ();

  /**
   * Modify the poniter to the left part of the OR
   * @param value is the new structure we want to put in the OR
   */       
  void set_pTerm_1 (operation * value);
  /**
   * Modify the poniter to the left part of the OR
   * @param value is the new structure we want to put in the OR
   */ 
  void set_pTerm_2 (operation * value);
      
  /**	
   * Return the value of the structure pointed by the operator. It is the maximum between the value of the two pointed structure.
   * @see operation
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */    
  float get_value(predicate_list *p, fuzzy_data_list *f);
  /**	
   * Return the reliability of the structure pointed by the operator. It is the maximum between the reliability of the two pointed structure.
   * @see operation
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */  
  float get_reliability(predicate_list *p, fuzzy_data_list *f);
      
 private:

  operation *pTerm_1;
  operation *pTerm_2;

};


/**
* This class inherits from operation and specifies it to be a data operator, one of the two types of leaves in a predicate tree.
* @short data operation
*/

class data_node : public operation 
{

 public:
  /**
   * Constructor generated by the UML software used to build Brian. It return an empty data node.
   */
  data_node();

  /**	
   * Constructor that build a data node
   * @param aname is the name of the fuzzy data related
   * @param alabel is the name of the fuzzy data related
   */
  data_node(char* aname,char* alabel);

  /**
   * Copy constructor generated by the UML software used to build Brian. It return a copy of the data node passed.
   */
  data_node(const data_node &right);
      
  /**	
   * Destructor destroy a data node freeing its name and label
   */
  virtual ~data_node();

  /**	
   * Return the membership value of the fuzzy data related to the data node finding it into the fuzzy data list.
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */  
  float get_value(predicate_list *p, fuzzy_data_list *f);
  /**	
   * Return the reliability of the fuzzy data related to the data node finding it into the  fuzzy data list.
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */
  float get_reliability(predicate_list *p, fuzzy_data_list *f);

 private:

  char *name;
  char *label;

};


/**
* This class inherits from operation and specifies it to be a predicate operator, one of the two types of leaves in a predicate tree.
* @short predicate operation
*/

class predicate_node : public operation 
{

 public:
  /**
   * Constructor generated by the UML software used to build Brian. It return an empty predicate node.
   */
  predicate_node();

  /**	
   * Constructor that build a data node
   * @param aname is the name of the predicate related
   */
  predicate_node(char* aname);

  /**
   * Copy constructor generated by the UML software used to build Brian. It return a copy of the predicate node passed.
   */
  predicate_node(const predicate_node &right);

  /**	
   * Destructor destroy a data node freeing its name
   */
  virtual ~predicate_node();

  /**	
   * Return the membership value of the predicate related to the predicate node finding it into the predicate data list. So the predicate used must be already computed.
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */  
  float get_value(predicate_list *p, fuzzy_data_list *f);
  /**	
   * Return the reliability of the predicate related to the predicate node finding it into the predicate data list. So the predicate used must be already computed.
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */  
  float get_reliability(predicate_list *p, fuzzy_data_list *f);

 private:

  char* name;

};

/**
* This class implements the base node from which the predicate tree is build.
* @short base node of a tree
*/

class aggregation_tree: public operation
{

 public:
  /**
   * Constructor generated by the UML software used to build Brian. It return an empty aggregation tree node.
   */  
  aggregation_tree();

  /**
   * Copy constructor generated by the UML software used to build Brian. It return a copy of the aggregation tree passed.
   */
  aggregation_tree(char *aname,operation * apTerm);

  /**	
   * Destructor destroy an aggregation tree
   */
  virtual ~aggregation_tree();

  /**	
   * Return the poniter to the predicate structure
   * @return a pointer to an operation
   */  
  operation * get_pTerm ();
  /**
   * Modify the poniter to the predicate structure
   * @param value is the new structure we want to use for the predicate
   */ 
  void set_pTerm (operation * value);

  /**	
   * Return the name of the predicate headed
   * @return a string 
   */  
  char * get_name ();
    /**
   * Modify the name of the predicate
   * @param value is the new name of the predicate
   */ 
  void set_name (char * value);

  /**	
   * Return the membership value of the predicate we would like to compute.
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */    
  float get_value(predicate_list *p, fuzzy_data_list *f);
  /**	
   * Return the reliability of the predicate we would like to compute.
   * @return a value
   * @param p is a pointer to a list of predicates
   * @param f is a pointer to a fuzzy data list
   */  
  float get_reliability(predicate_list *p, fuzzy_data_list *f);

 private:

  char *name;
  operation *pTerm;
};


/**
* this structure is used by multimaps to keep the insertion order
*/ 
struct ins_prd {
  bool operator() (const char *s1, const char *s2) const
  {
    return 0;
  }
};

/**
 * Instantiation of multimap template in order to create an aggregation tree list
 * @see prd_tree_map
 */
typedef multimap <const char *, aggregation_tree *, ins_prd> aggr_tree_multimap;


/**
* Class implementing the parser user to read from file an aggregation tree list
* @short read aggregation trees from file
*/

class aggr_tree_parser 
{

 public:
  /**
   * Constructor: build a aggr_tree parser that read aggregation trees from the afilename file.
   */
  aggr_tree_parser(char * afilename);

  /**
   * Copy constructor generated by the UML software used to build Brian. It return a copy of the aggregation tree parser.
   */
  aggr_tree_parser(const aggr_tree_parser &right);

  /**	
   * Destructor: destroy an aggregation trees parser freeing the filename.
   */
  virtual ~aggr_tree_parser();

  /**	
   * Method that read aggregation tree definitions from a file
   * @return the same pointer as the given one.
   * @param pointer to an existing aggregation tree list.
   */  
  virtual aggr_tree_multimap * get_aggr_trees (aggr_tree_multimap *anaggrmmap);

 private:

  char * filename;
   
};

// inline methods

inline operation * op_not::get_pTerm () 
{
  return pTerm;
}

inline void op_not::set_pTerm (operation * value)
{
  pTerm = value;
}

inline operation * op_and::get_pTerm_1 () 
{
  return pTerm_1;
}

inline void op_and::set_pTerm_1 (operation * value)
{
  pTerm_1 = value;
}

inline operation * op_and::get_pTerm_2 () 
{
  return pTerm_2;
}

inline void op_and::set_pTerm_2 (operation * value)
{
  pTerm_2 = value;
}

inline operation * op_or::get_pTerm_1 () 
{
  return pTerm_1;
}

inline void op_or::set_pTerm_1 (operation * value)
{
  pTerm_1 = value;
}

inline operation * op_or::get_pTerm_2 () 
{
  return pTerm_2;
}

inline void op_or::set_pTerm_2 (operation * value)
{
  pTerm_2 = value;
}

//***********************************************************************
//***********************************************************************

// Class aggregation_tree 

//***********************************************************************
// Get and Set Operations for Class Attributes (inline)

inline char * aggregation_tree::get_name () 
{
  char * ch = (char *) malloc(strlen(name)+1);
  strcpy (ch,name);
  return ch;
}

inline void aggregation_tree::set_name (char * value)
{
  if (name != NULL) free(name);
  name = (char *) malloc(strlen(value)+1);
  strcpy(name, value);
}

inline operation * aggregation_tree::get_pTerm () 
{
  return pTerm;
}

inline void aggregation_tree::set_pTerm (operation * value)
{
  pTerm = value;
}

#endif

