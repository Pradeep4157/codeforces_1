#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS


if i try to give ambiverts new table that is good

for extroverts becuase  they have more options..

but that dec introverts options..

maybe the questions is like i have to  pair s - 1 extroverts

with each ambivert..

now at some i the no of extroverts should be <= ambiverts * (s - 1)

if they are more then no..

else :
    i still need to checks :

        introverts + extroverts + s - 1 / s - 1 tables ..


        if not we will have to kick some..

        its better to kick introverts because they take the

        whole table..

    I WILL KEEP TRACK OF INTROVERTS, AMBIVERTS : SEATS LEFT..



    so at every i,

    IF THIS IS INTROVERT :

        if seats are left, then i will place it

        else :
            if i can merge some ambivert with some other ambivert

            then yes else no..

            how will i know this :

                every ambivert has s - 1 seats so if there are more

                then s - 1 then do ambivert -= s - 1
                tables++
                ambivert--

    IF THIS IS AMBIVERTS:

        i will try to assign new table and if not available :

            i will try to  kick some introvert :
                and do ambivert += s - 1
            else kick this guy..

    BUT

    IF THIS IS EXTROVERT :

        if ambivert value is 0 then kick else

        ambivert--


    ok so extro can sit with intro as well..


    when an intro comes we can only ask a group of ambivert which might include extrovert (mostly not) to combine with some other group of ambivert

    or combine with some group of introvert..

    or should i change the strategy that whenever an ambivert comes i will try to make him sit with some introvert..

    if no places left then i will make him sit in some new table..

    now when extrovert comes i will try to make him also sit with some extrovert and if no place left then i will try to make him sit with some ambivert

    and if no place left there as well then i will try to  take some ambivert that is sitting with some introvert and assign him new table and make extrovert

    sit with that table where this ambivert was sitting..











*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, tables_left, seats_per_table;
        cin >> n >> tables_left >> seats_per_table;
        string s;
        cin >> s;
        int res = 0;
        int ambiverts = 0;
        int introverts = 0;
        int ambi_with_intro = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char a = s[i];
            if (a == 'E')
            {
                // i will try to make him also sit with some intro..
                if (introverts > 0)
                {
                    introverts--;
                }
                // else i will try to make him sit with some ambivert..
                else if (ambiverts > 0)
                {
                    ambiverts--;
                }
                // else i will try to take some ambivert make him sit in new table and then let this nigga sit with that intro..
                else if (tables_left > 0)
                {
                    if (ambi_with_intro > 0)
                    {
                        ambi_with_intro--;
                        tables_left--;
                        ambiverts += (seats_per_table - 1);
                    }
                    else
                    {
                        // we cant help him..
                        res++;
                    }
                }
                else
                {
                    // we still cant help him..
                    res++;
                }
            }
            else if (a == 'A')
            {
                // i will try to make him sit with some introvert..
                if (introverts > 0)
                {
                    introverts--;
                    ambi_with_intro++;
                }
                else
                {
                    if (ambiverts > 0)
                    {

                        // we can make him sit with some other ambi..
                        ambi_with_intro++;
                        ambiverts--;
                    }
                    else
                    {

                        // i will need to assign this nigga a new table..
                        if (tables_left > 0)
                        {
                            tables_left--;

                            ambiverts += (seats_per_table - 1);
                        }
                        else
                            res++; // i cant help u bro..
                    }
                }
            }
            else
            {
                // if there are no new seats left then gg..
                if (tables_left <= 0)
                {
                    res++;
                }
                else
                {
                    // i will assign new table to this nigga..
                    introverts += (seats_per_table - 1);
                    tables_left--;
                }
            }
        }
        int m = s.size();
        res = m - res;
        cout << res << endl;
    }
    return 0;
}
