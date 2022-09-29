#include "cJSON.h"
#include "cJSON_Utils.h"
#include <stdio.h>
#include <string.h>
int main()

{
    /*
    FILE *ptr;
    if((ptr = fopen("sample.json", "r")) == NULL)
    {
        printf("Error opening file");
        return 1;
    }
*/

    cJSON *json = NULL;
    cJSON *fName = NULL;
    cJSON *lName = NULL;
    cJSON *mName = NULL;
    cJSON *acctType = NULL;
    cJSON *balance = NULL;
    char* body;
    
    
    char* buffer = "{\"fname\": \"Olumide\", \"lname\": \"Oludare\", \"mname\": \"Ezekiel\", \"acctType\": \"Savings\", \"balance\": \"2550\"}";

    body = strchr(buffer, '{');
   

    if (body == NULL) {
        return -1;
    }

    json = cJSON_Parse(body);
    if (!json || cJSON_IsNull(json)) {
        cJSON_Delete(json);
        return -1;
    }

    fName = cJSON_GetObjectItemCaseSensitive(json, "fname");
     if (!fName || !cJSON_IsString(fName)) {
        cJSON_Delete(fName);
        return -1;
    }
    printf("First Name: %s\n", fName->valuestring);
    
    lName = cJSON_GetObjectItemCaseSensitive(json, "lname");
    if (!lName || !cJSON_IsString(lName)) {
        cJSON_Delete(lName);
        return -1;
    }
    printf("Last Name: %s\n", lName->valuestring);

    mName = cJSON_GetObjectItemCaseSensitive(json, "mname");
    if (!mName || !cJSON_IsString(mName)) {
        cJSON_Delete(mName);
        return -1;
    }
    printf("Middle Name: %s\n", mName->valuestring);

    acctType = cJSON_GetObjectItemCaseSensitive(json, "acctType");
    if (!acctType || !cJSON_IsString(acctType)) {
        cJSON_Delete(acctType);
        return -1;
    }
    printf("Account Type: %s\n", acctType->valuestring);

    balance = cJSON_GetObjectItemCaseSensitive(json, "balance");
    if (!balance || !cJSON_IsString(balance)) {
        cJSON_Delete(balance);
        return -1;
    }
    printf("Account Balance: %s\n", balance->valuestring);

    cJSON_Delete(json);
    return 0;
}