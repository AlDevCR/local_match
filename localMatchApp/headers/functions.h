#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "events.h"

/*!
 * The class of functions is created to
 * be able to develop the functions
 * that will manage the database
 */
class Functions
{
public:
    Functions();
    /*!
     * The function to select all the
     * information of the events
     */
    Events SelectEvent(int i_index);
};

#endif // FUNCTIONS_H
