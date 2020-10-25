#include <stdio.h>
#include <math.h>

#define THRESHOLD 1.0 / 1000000.0

void solve_systems_of_equations_for_double_type(double deviation, double *x2, double *y2)
{
	*y2 = (0.0001 + deviation)/0.0001;
	*x2 = 2.0 - *y2;
}

void solve_systems_of_equations_for_float_type(float deviation, float *x2, float *y2)
{
	*y2 = (0.0001f + deviation)/0.0001f;
	*x2 = 2.0f - *y2;
}

double calculating_distance_between_points_for_double_type(double x1, double x2, double y1, double y2)
{
	double distance_between_points = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); 
	double result = sqrt(distance_between_points);
	return result;
}

float calculating_distance_between_points_for_float_type(float x1, float x2, float y1, float y2)
{
	float distance_between_points = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); 
	float result = sqrtf(distance_between_points);
	return result;
}

void experiment_with_double_type()
{
	double x1 = 1.0, y1 = 1.0, deviation = 0.0001; 
	double x2, y2;
	int iteration_count = 0;

	solve_systems_of_equations_for_double_type(0.0001, &x2, &y2);
	printf("Solution: x, y = (%.20lf; %.20lf)\n", x2, y2);
	double result = calculating_distance_between_points_for_double_type(x1, x2, y1, y2);
	printf("distance between points: %.20lf \n", result);

	while (result >= THRESHOLD)
	{
		deviation = deviation / 2.0;
		solve_systems_of_equations_for_double_type(deviation, &x2, &y2);
		printf("Solution after deviation reduction: x, y = (%.20lf; %.20lf)\n", x2, y2);
		result = calculating_distance_between_points_for_double_type(x1, x2, y1, y2); 
		printf("Distance between points after deviation reduction: %.20lf \n", result);
		iteration_count++;
		printf("Counting iterations of a double experiment: %d \n \n", iteration_count);

	}
}

void experiment_with_float_type()
{
	float x1 = 1.0f, y1 = 1.0f, deviation = 0.0001f; 
	float x2, y2;
	int iteration_count = 0;

	solve_systems_of_equations_for_float_type(0.0001, &x2, &y2);
	printf("Solution: x, y = (%.20f; %.20f)\n", x2, y2);
	double result = calculating_distance_between_points_for_float_type(x1, x2, y1, y2);
	printf("distance between points: %.20f \n ", result);

	while (result >= THRESHOLD)
	{
		deviation = deviation / 2.0f;
		solve_systems_of_equations_for_float_type(deviation, &x2, &y2);
		printf("Solution after deviation reduction: x, y = (%.20f; %.20f)\n", x2, y2);
		result = calculating_distance_between_points_for_float_type(x1, x2, y1, y2); 
		printf("Distance between points after deviation reduction: %.20f \n", result);
		iteration_count++;
		printf("Counting iterations of a float experiment: %d \n \n", iteration_count);
	}

}

int main()
{
	printf("Experiment with the double type: \n \n");
	experiment_with_double_type();
	printf("Experiment with the float type: \n \n");
	experiment_with_float_type();
	
	return 0;
}