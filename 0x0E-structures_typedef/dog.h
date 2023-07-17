#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Represents a dog with its name, age, and owner.
 * @name: Pointer to the name of the dog.
 * @age: Age of the dog.
 * @owner: Pointer to the owner's name.
 *
 * Description: This structure represents a dog and holds information
 *              about its name, age, and owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_H */
