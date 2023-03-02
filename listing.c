#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ROW_LENGTH 1024
#define ROW_VALUES 10

struct listing_obj
{
	int id, host_id, minimum_nights, number_of_reviews, calculated_host_listings_count, availability_365; 
	char *host_name, *neighbourhood_group, *neighbourhood, *room_type;  
	float latitude, longitude, price;  
};

struct listing_obj getValues(char* row){  
   struct listing_obj obj;  
 
   obj.id = atoi(strtok(row, ","));  
   obj.host_id = atoi(strtok(NULL, ","));  
   obj.host_name = strdup(strtok(NULL, ","));  
   obj.neighbourhood_group = strdup(strtok(NULL, ","));  
   obj.neighbourhood = strdup(strtok(NULL, ","));  
   obj.latitude = atof(strtok(NULL, ","));  
   obj.longitude = atof(strtok(NULL, ","));  
   obj.room_type = strdup(strtok(NULL, ","));  
   obj.price = atof(strtok(NULL, ","));  
   obj.minimum_nights = atoi(strtok(NULL, ","));  
   obj.number_of_reviews = atoi(strtok(NULL, ","));  
   obj.calculated_host_listings_count = atoi(strtok(NULL, ","));  
   obj.availability_365 = atoi(strtok(NULL, ","));  
 
   return obj;  
}

void printFiles(FILE* file_name,int length, struct listing_obj *temp) {
	fprintf(file_name, "id,host_id,host_name,neighbourhood_group,neighbourhood,latitude,longitude,room_type,price,minimum_nights,number_of_reviews,calculated_host_listings_count,availability_365 \n");
	for (int i = 0; i < length; i++) {
        fprintf(file_name, "%d,%d,%s,%s, %s,%f,%f,%s,%f,%d,%d,%d,%d\n", temp[i].id, temp[i].host_id, temp[i].host_name, temp[i].neighbourhood_group, temp[i].neighbourhood, temp[i].latitude, temp[i].longitude, temp[i].room_type, temp[i].price, temp[i].minimum_nights, temp[i].number_of_reviews, temp[i].calculated_host_listings_count, temp[i].availability_365);
    }
    fclose(file_name);
}

int sortByHostName(const void* obj1, const void* obj2) {
   	const struct listing_obj* row1 = (const struct listing_obj *) obj1;
	const struct listing_obj* row2 = (const struct listing_obj *) obj2;
	return strcmp(row1->host_name, row2->host_name);
}
int sortByPrice(const void* obj1, const void* obj2) {
	const struct listing_obj* row1 = (const struct listing_obj *) obj1;
    const struct listing_obj* row2 = (const struct listing_obj *) obj2;
	return row1->price - row2->price;
}
int main(int argc,char **argv) {
    if (argc != 2){
		printf("Usage: %s <listings_csv> \n", argv[0]);
		exit (-1);
	}
	struct listing_obj* list_values = (struct listing_obj*) malloc(2500 * sizeof(struct listing_obj));
    // reading csv file
	FILE* listing_csv = fopen(argv[1], "r");
	if(listing_csv == NULL) {
		printf("Unable to read the given CSV file %s.\n", argv[1]);
	}
	//reading csv values
	char row[ROW_LENGTH];
	int index = 0; 
	while (fgets(row, ROW_LENGTH, listing_csv) != NULL){ 
		list_values[index++] = getValues(row);
	} 

	//Sorting By Price
	qsort(list_values, index, sizeof(struct listing_obj), sortByHostName);
	FILE* host_name_listing = fopen("host_name_listing.csv", "w");
	printFiles(host_name_listing, index, list_values);

	//Sorting By Price
	qsort(list_values, index, sizeof(struct listing_obj), sortByPrice);
	FILE* price_listing = fopen("price_listing.csv", "w");
	printFiles(price_listing, index, list_values);

	free(list_values);
	fclose(listing_csv);
	return 0;
}
/**
 * References:
 * https://github.com/UAB-CS-332-532/Lab-06
 * https://www.geeksforgeeks.org/c-qsort-function/
 * https://www.geeksforgeeks.org/sorting-array-structures-using-qsort-in-c/
 * https://stackoverflow.com/questions/190229/printf-with-a-structure-array-in-c
 * https://www.geeksforgeeks.org/dynamically-allocate-memory-for-structures-in-c/
 * https://www.geeksforgeeks.org/csv-file-management-using-c/
 * https://stackoverflow.com/questions/2527493/how-to-get-the-keys-of-a-structure-in-c
 * https://stackoverflow.com/questions/29057495/sorting-an-array-of-structures-containing-string-fields-using-qsort-in-c
*/