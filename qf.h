#include <stdio.h>
#include <stdbool.h>
#include <bits.h>
#include <string.h>
#include <math.h>

#define ll long long
#define q 1000


struct Node
{
    bool is_occupied, is_countinuation, is_shifted;
    int value;
};
typedef struct Node node;

struct Pos_run
{
    int start, end;
} typedef run_pos;

int fingerprint(char *x)
{
    int hash;
    int l = strlen(x);
    for (int i = 0; i < l; i++)
    {
        hash = (int)(((int)x[i] * i));
    }
    return hash;
}

node *shiftALLright(node *QF, int n)
{
    int temp1 = QF[n].value, temp2 = QF[n + 1].value;
    for (int i = n + 1; QF[i].is_countinuation != false && QF[i].is_occupied != false && QF[i].is_shifted != false; i++)
    {
        QF[i].value = temp1;
        temp1 = temp2;
    }

    return QF;
}

node *shiftAllLeft(node *QF, int n)
{
    int i = n;
    while ( QF[i].is_countinuation != false && QF[i].is_occupied != false && QF[i].is_shifted != false)
    {
        QF[i - 1].value = QF[i].value;
        i++;
    }
    return QF;
}

run_pos qf_scan(int f_q, node *QF)
{
    int j = f_q;
    while (QF[j].is_shifted == true)
    {
        j = j - 1;
    }
    run_pos run;
    run.start = j;
    while (j != f_q)
    {
        do
        {
            run.start = run.start + 1;
        } while (QF[run.start].is_countinuation != false);
        do
        {
            j = j + 1;
        } while (QF[j].is_occupied != true);
    }

    run.end = run.start;

    do
    {
        run.end = run.end + 1;
    } while (QF[run.end].is_countinuation != false);

    return run;
}

bool qf_insert(char* x, node *QF)
{
    int f = fingerprint(x);
    int f_r = f;
    int f_q = f % (int)pow(2, q);
    if (QF[f_q].is_occupied == false && QF[f_q].value == -1)
    {
        QF[f_q].value = f_r;
        QF[f_q].is_occupied = true;
        return true;
    }
    QF[f_q].is_occupied = 1;
    run_pos run = qf_scan(f_q, QF);
    for (int i = run.start; i < run.end; i++)
    {
        if (QF[i].value == f_r)
            return true;
        else if (QF[i].value > f_r)
        {
            QF = shiftALLright(QF, i);
            QF[i].value = f_r;
            return true;
        }
    }

    QF = shiftALLright(QF, run.end + 1);
    QF[run.end + 1].value = f_r;

    return true;
}

bool qf_lookup(char* x, node *QF)
{
    int f = fingerprint(x);
    int f_r = f;
    int f_q = f % (int)pow(2, q);
    if (QF[f_q].is_occupied == false)
    {
        return false;
    }
    run_pos run = qf_scan(f_q, QF);

    for (int i = run.start; i < run.end; i++)
    {
        if (QF[i].value == f_r)
            return true;
    }

    return false;
}

bool qf_delete (char* x, node *QF)
{
    int f = fingerprint(x);
    int f_r = f;
    int f_q = f % (int)pow(2, q);
    if (QF[f_q].is_occupied == false)
    {
        return false;
    }
    run_pos run = qf_scan(f_q, QF);

    for (int i = run.start; i < run.end; i++)
    {
        if (QF[i].value == f_r)
        {
            QF[i].value = -1;
            if (run.start == run.end)
                QF[i].is_occupied = false;
            else if (i < run.end)
                QF = shiftAllLeft(QF, i + 1);

            return true;
        }
    }

    return false;
}