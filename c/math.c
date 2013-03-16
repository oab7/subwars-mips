/* math.c
 * Vector Math and other mathematical utilities
 */

#include "math.h"

vector add(vector v0, vector v1)
{
    // Allocate the resultant struct
    vector sum;

    // Add the components
    sum.x = v0.x + v1.x;
    sum.y = v0.y + v1.y;

    // Return the struct
    return sum;
}

vector mult(vector v, int s)
{
    // Allocate the resultant struct
    vector product;

    // Multiply components by scalar
    product.x = v.x * s;
    product.y = v.y * s;

    // Return the struct
    return product;
}

int dot(vector v0, vector v1)
{
    // Allocate the resultant int
    int dotProduct;

    // Multiply the components and add
    dotProduct = v0.x * v1.x + v0.y * v1.y;

    // Return the int
    return dotProduct;
}

bool collide(vector initial, vector ray, vector target)
{
    // Subtract initial from target to get expected ray
    vector expected = add(target, mult(initial, -1));

    // Dot expected ray with actual ray
    int dotProduct = dot(expected, ray);

    // If product is equal to the product of lengths, vectors are parallel
    // Compare dot product (squared) with product of lengths (squared)
    return dotProduct * dotProduct == dot(expected, expected) * dot(ray, ray);
}