#include "dog.h"

void init_dog(Dog *d, char *name, float age, char *owner) {
    if (d == NULL) {
        /* Handle case where d pointer is NULL  */
        return;
    }
    
    d->name = name;
    d->age = age;
    d->owner = owner;
}
