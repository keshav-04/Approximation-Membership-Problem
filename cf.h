#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MaxIterations 3
#define m 2048

// function to convert given charracter array of username into its fingerprint(fp).
int cf_fingerprint(char *x)
{
    int l = strlen(x);
    long int fp = 0;
    for (int i = 0; i < l; i++)
    {
        fp += (long int)(((int)x[i] + i) / 2);
    }
    return fp % m;
}

int hash(int f)
{
    int f2 = 0, i = 1;
    while (f)
    {
        f2 += f / i;
        i++;
        f = f / i;
    }

    return f2;
}

// function to insert the given usename in the Dataset of cuckoo filter.
bool cf_insert(char *x, int *CF)
{
    int f = cf_fingerprint(x);
    int i = f;
    int j = i ^ (hash(f));
    if (CF[i] == -1)
    {
        CF[i] = f;
        return true;
    }
    if (CF[j] == -1)
    {
        CF[j] = f;
        return true;
    }
    int k = i;
    bool k2;
    for (int n = 0; n < MaxIterations; n++)
    {
        int pos = k;
        int f2 = CF[pos];
        int j2 = pos ^ (hash(f2));
        if (CF[j2] == -1)
        {
            k2 = true;
        }
        f = f2;
    }
    if (k2 == true)
    {
        for (int n = 0; n < MaxIterations; n++)
        {
            int pos = k;
            int f2 = CF[pos];
            CF[pos] = f;
            int j2 = pos ^ (hash(f2));
            if (CF[j2] == -1)
            {
                CF[j2] = f2;
                return true;
            }
            f = f2;
        }
    }
    else
    {
        for (int n = 0; n < MaxIterations; n++)
        {
            int pos = j;
            int f2 = CF[pos];
            CF[pos] = f;
            int j2 = pos ^ (hash(f2));
            if (CF[j2] == -1)
            {
                CF[j2] = f2;
                return true;
            }
            f = f2;
        }
    }

    return false;
}

// function to delete a username(if present) from the data set.
bool cf_delete(char *x, int *CF)
{
    int f = cf_fingerprint(x);
    int i = f;
    int j = i ^ f;
    if (f == CF[i] || f == CF[j])
    {
        CF[i] = -1;
        return true;
    }
    return false;
}

// funtion to lookup for the username in the data set.
bool cf_lookup(char *x, int *CF)
{
    int f = cf_fingerprint(x);
    int i = f;
    int j = i ^ f;
    if (f == CF[i] || f == CF[j])
    {
        return true;
    }
    return false;
}