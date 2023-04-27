// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// ADD THE TAX TO THE BILL BEFORE CALCULATING THE TIP

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    // tax value based on the bill
    // if the bill is 20 and the tax is 10
    // the tax_value will be 10% of the bill
    float tax_value = (tax / 100) * bill;

    // add the tax value to the bill
    float bill_with_tax = tax_value + bill;

    // after adding the bill and the tax we get the tip percentage
    float tip_value = ((float) tip / 100) * bill_with_tax;


    // add the tip value to the new bill and divide by two
    float new_bill = (tip_value + bill_with_tax) / 2;

    return new_bill;
}
