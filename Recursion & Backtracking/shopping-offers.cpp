// https://leetcode.com/problems/shopping-offers/

/*
Example 1:
Input: price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
Output: 14
Explanation: There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.

Example 2:
Input: price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
Output: 11
Explanation: The price of A is $2, and $3 for B, $4 for C. 
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
You cannot add more items, though only $9 for 2A ,2B and 1C.
*/

map<vector<int>, int> state;

int shoppingOffers(vector<int> &price, vector<vector<int> > &special, vector<int> &needs)
{
    if (state[needs])
        return state[needs];

    int bestPrice = noOffers(price, needs);
    for (auto offer : special)
    {
        subtractOffer(offer, needs);
        if (noNegativeNeeds(needs))
        {
            int newPrice = offer.back() + shoppingOffers(price, special, needs);
            bestPrice = min(bestPrice, newPrice);
        }
        addOffer(offer, needs);
    }

    return state[needs] = bestPrice;
}

int noOffers(vector<int> &price, vector<int> &needs)
{
    int cost = 0;
    for (int i = 0; i < price.size(); i++)
        cost += price[i] * needs[i];
    return cost;
}

void subtractOffer(vector<int> &offer, vector<int> &needs)
{
    for (int i = 0; i < needs.size(); i++)
        needs[i] -= offer[i];
}

void addOffer(vector<int> &offer, vector<int> &needs)
{
    for (int i = 0; i < needs.size(); i++)
        needs[i] += offer[i];
}

bool noNegativeNeeds(vector<int> &needs)
{
    for (auto need : needs)
        if (need < 0)
            return false;
    return true;
}