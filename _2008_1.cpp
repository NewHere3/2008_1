#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

void read(int m_in[], int m_off[], int& n);
void write(int m_in[], int m_off[]);
int find(int m_in[]);

int main()
{
    int m_in[100] = { 0 };
    int m_off[100] = { 0 };
    int n;
    read(m_in, m_off, n);
    write(m_in, m_off);
    return 0;
}

void read(int m_in[], int m_off[], int& n)
{
    ifstream duom("Duomenys.txt");
    duom >> n;
    for (int i = 0; i < n; i++)
    {
        int stotele = 0;
        int temp = 0;
        duom >> stotele;
        duom >> temp;
        if(temp<0)
        {
            m_off[stotele] += temp;
        }
        else
        {
            m_in[stotele] += temp;
        }

    }
}

void write(int m_in[], int m_off[])
{
    ofstream rez("Rezultatai.txt");
    for (int i = 0; i < 100; i++)
    {
        if (m_in[i] > 0)
        {
            rez << setw(6) << i;
        } 
    }
    rez << '\n';
    for (int i = 0; i < 100; i++)
    {
        if (m_in[i] > 0)
        {
            rez << setw(6) << m_in[i];
        }
    }
    rez << '\n';
    for (int i = 0; i < 100; i++)
    {
        if (m_in[i] > 0)
        {
            rez << setw(6) << m_off[i];
        }
    }
    rez << '\n';
    rez << setw(6) << find(m_in);
}

int find(int m_in[])
{
    int x = 0;
    int y;
    for (int i = 0; i < 100; i++)
    {
        if (m_in[i] > x)
        {
            x = m_in[i];
            y = i;
        }
    }
    return y;
}