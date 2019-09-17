#ifndef __FUNCTIONS__
#define __FUNCTIONS__
void output_vec(vector<int> &a)
{
    cout << a[0];
    for (int i = 1; i < a.size(); i++)
        cout << " -> " << a[i];
    cout << endl;
}

#endif