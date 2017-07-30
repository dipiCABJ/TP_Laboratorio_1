#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int resizeDown(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void** pElements;
    this=(ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this,void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL)
    {
       if(this->size >= this->reservedSize)
        {
           if(resizeUp(this) == -1)
             return returnAux;
        }
        this->pElements[this->size] = pElement;
        this->size++;
        returnAux = 0;
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int i,returnAux = -1;
    if(this != NULL)
    {
       for(i=0;i<this->size;i++)
          free(this->pElements[i]);
       free(this);
       returnAux = 0;
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
       returnAux = this->size;
    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this , int index)
{
    void* returnAux = NULL;
    if(this != NULL)
      {
         if(index >= 0 && index < this->len(this))
           returnAux = this->pElements[index];
      }
    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int i,returnAux = -1;
    if(this != NULL && pElement != NULL)
      {
        for(i=0;i<this->size;i++)
         {
           returnAux = 0;
           if(this->pElements[i] == pElement)
            {
              returnAux = 1;
              break;
            }
         }
      }
    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL)
      {
         if(index >= 0 && index < this->len(this))
         {
            this->pElements[index] = pElement;
            returnAux = 0;
         }
      }
    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    if(this != NULL)
     {
       if(index >= 0 && index < this->len(this))
       {
          if(contract(this,index)== -1)
            return returnAux;
       }
       returnAux = 0;
      }
    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    void** auxElements;
    if(this != NULL)
     {
       auxElements = (void**)realloc(this->pElements,sizeof(void*)*AL_INITIAL_VALUE);
       if(auxElements != NULL)
        {
          this->size = 0;
          this->pElements = auxElements;
          this->reservedSize = AL_INITIAL_VALUE;
          returnAux = 0;
        }
     }
    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    returnAux = al_newArrayList();
    if(this != NULL || returnAux != NULL)
    {
      returnAux = this;
    }
    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL)
      {
        if(index == this->len(this))
        {
           this->set(this,index,pElement);
           this->size++;
           if(this->len(this)>= this->reservedSize)
              resizeUp(this);
           returnAux = 0;
        }
        if(index >= 0 && index < this->len(this))
        {
           expand(this,index);
           this->set(this,index,pElement);
           this->size++;
           returnAux = 0;
        }
      }
    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int i,returnAux = -1;
    if(this != NULL && pElement != NULL)
      {
         for(i=0;i<this->len(this);i++)
          {
            if(this->pElements[i] == pElement)
            returnAux = i;
          }
      }
    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
      {
        if(this->len(this) > 0)
        {
          returnAux = 0;
        }
        else
        {
          returnAux = 1;
        }
      }
    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL)
    {
       if(index >= 0 && index < this->len(this))
       {
          returnAux = this->pElements[index];
          contract(this,index);
       }
    }
    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList *returnAux = NULL;
    int i;
    if (this != NULL)
    {
        if (from >= 0 && from < to && to <= this->size)
        {
            returnAux = al_newArrayList();

            for (i = from; i < to; i++)
            {
                al_add(returnAux, al_get(this, i));
            }
        }
    }
    return returnAux;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int i,returnAux = -1;
    if(this != NULL && this2 != NULL)
    {
      for(i=0;i<this2->len(this2);i++)
      {
         if(this2->contains(this,this2->get(this2,i)) == 1)
         {
            returnAux = 1;
         }
         else
         {
            returnAux = 0;
         }
         break;
      }
    }
    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int i,j,returnAux = -1;
    void* auxiliar = NULL;
    if(this == NULL || pFunc == NULL)
        return returnAux;

    switch(order)
    {
      case 0:
        for(i=0;i<(this->len(this))-1;i++)
         {
           for(j=i+1;j<(this->len(this));j++)
            {
                 if(pFunc(this->pElements[i],this->pElements[j])== -1)
                  {
                    auxiliar = this->get(this,i);
                    this->set(this,i,this->pElements[j]);
                    this->set(this,j,auxiliar);
                  }
            }
         }
       returnAux = 0;
       break;

       case 1:
         for(i=0;i<(this->len(this))-1;i++)
         {
           for(j=i+1;j<(this->len(this));j++)
            {
                 if(pFunc(this->pElements[i],this->pElements[j])== 1)
                  {
                    auxiliar = this->get(this,i);
                    this->set(this,i,this->pElements[j]);
                    this->set(this,j,auxiliar);
                  }
            }
         }
       returnAux = 0;
       break;

       default:
        returnAux = -1;
        break;
    }
    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** auxElement;

    if(this != NULL)
    {
      //this->pElements
      auxElement = (void**)realloc(this->pElements,sizeof(void*)*(this->reservedSize + AL_INCREMENT));
      if(auxElement != NULL)
      {
         this->pElements = auxElement;
         this->reservedSize+=AL_INCREMENT;
         returnAux = 0;
      }
    }
    return returnAux;

}

/** \brief Reduce the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeDown(ArrayList* this)
{
    int returnAux = -1;
    void** auxElement;

    if(this != NULL)
    {
      //this->pElements
      auxElement = (void**)realloc(this->pElements,sizeof(void*)*(this->reservedSize - AL_INCREMENT));
      if(auxElement != NULL)
      {
         this->pElements = auxElement;
         this->reservedSize-=AL_INCREMENT;
         returnAux = 0;
      }
    }
    return returnAux;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int i,returnAux = -1;
    if(this != NULL)
    {
        if(index >= 0 && index <= this->size)
        {
           for(i=this->size;i>=index;i--)
             {
               if(this->size >= this->reservedSize)
               {
                 resizeUp(this);
               }
               this->set(this,i,this->get(this,i));
             }
        }
        this->size++;
        returnAux = 0;
    }
    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int i,returnAux = -1;
    if(this != NULL)
    {
      if(index >= 0 && index < this->len(this))
      {
        for(i=index;i<(this->len(this));i++)
          this->set(this,i,this->get(this,(i+1)));
        if((this->reservedSize - this->len(this)> AL_INCREMENT))
           resizeDown(this);
        this->size--;
        returnAux = 0;
      }
    }
    return returnAux;
}