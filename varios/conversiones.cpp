/*
 * Conversiones de unidades
 * Autor: Jairo Flores
 * Conversiones comunes para longitud, masa, tiempo, temperatura, etc.
 */

#include <bits/stdc++.h>
using namespace std;

// Longitud
double km_to_m(double km) { return km * 1000.0; }
double m_to_km(double m) { return m / 1000.0; }
double m_to_cm(double m) { return m * 100.0; }
double cm_to_m(double cm) { return cm / 100.0; }
double inch_to_cm(double in) { return in * 2.54; }
double cm_to_inch(double cm) { return cm / 2.54; }
double ft_to_m(double ft) { return ft * 0.3048; }
double m_to_ft(double m) { return m / 0.3048; }

// Masa
double kg_to_g(double kg) { return kg * 1000.0; }
double g_to_kg(double g) { return g / 1000.0; }
double lb_to_kg(double lb) { return lb * 0.45359237; }
double kg_to_lb(double kg) { return kg / 0.45359237; }

// Tiempo
double hr_to_min(double hr) { return hr * 60.0; }
double min_to_sec(double min) { return min * 60.0; }
double sec_to_ms(double sec) { return sec * 1000.0; }

// Temperatura
double celsius_to_fahrenheit(double c) { return (c * 9.0 / 5.0) + 32.0; }
double fahrenheit_to_celsius(double f) { return (f - 32.0) * 5.0 / 9.0; }
double celsius_to_kelvin(double c) { return c + 273.15; }
double kelvin_to_celsius(double k) { return k - 273.15; }

// Velocidad
double kmph_to_mps(double kmph) { return kmph / 3.6; }
double mps_to_kmph(double mps) { return mps * 3.6; }
double mph_to_kmph(double mph) { return mph * 1.60934; }
double kmph_to_mph(double kmph) { return kmph / 1.60934; }

// Area
double m2_to_km2(double m2) { return m2 / 1e6; }
double km2_to_m2(double km2) { return km2 * 1e6; }
double acre_to_m2(double acre) { return acre * 4046.85642; }
double m2_to_acre(double m2) { return m2 / 4046.85642; }

// Volumen
double l_to_ml(double l) { return l * 1000.0; }
double ml_to_l(double ml) { return ml / 1000.0; }
double gal_to_l(double gal) { return gal * 3.78541; } // gal (US)
double l_to_gal(double l) { return l / 3.78541; }

// Binario
double kb_to_bytes(double kb) { return kb * 1024.0; }
double mb_to_bytes(double mb) { return mb * 1024.0 * 1024.0; }
double gb_to_bytes(double gb) { return gb * 1024.0 * 1024.0 * 1024.0; }
double bytes_to_kb(double b) { return b / 1024.0; }
double bytes_to_mb(double b) { return b / (1024.0 * 1024.0); }
double bytes_to_gb(double b) { return b / (1024.0 * 1024.0 * 1024.0); }

// Prueba
int main() {
    cout << fixed << setprecision(2);
    cout << "5 km = " << km_to_m(5) << " m\n";
    cout << "100 F = " << fahrenheit_to_celsius(100) << " C\n";
    cout << "1 acre = " << acre_to_m2(1) << " m^2\n";
    cout << "1.5 GB = " << gb_to_bytes(1.5) << " bytes\n";
    return 0;
}

