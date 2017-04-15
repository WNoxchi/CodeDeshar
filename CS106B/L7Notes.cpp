// CS106B - WNx - Notes L7 - 12-Jan-2017 00:56

// Generic Plot function
void Plot(double start, double stop, double (fn)(double))
{
    double centerY = GetWindowHeight()/2.0;
    MovePen(start, centerY + fn(start));
    for (double x = start; x <= stop; x += Incr)
        LineTo(x, centerY + fn(x));
}

// Using Functions as Data!
//  client passes function by name to Plot which graphcs it
int main()
{
    Plot(0, 2, sin);
    Plot(1, 10, sqrt);
    Plot(2, 5, MyFunction);
    Plot(2, 5, GetLine); // doesn't compile!
    ....
}

//
