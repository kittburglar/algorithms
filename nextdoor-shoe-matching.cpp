/**
Problem:
Imagine you work at a store that sells shoes. You've been asked to take a pile of random shoes and sort them into valid pairs. A valid pair means they're the same style and there's 1 shoe for the right foot and 1 shoe for the left foot. (Forget about size for now).

More formally:

Create a function called 'sortShoes' which inputs `[Shoe]` (an array of shoes) and outputs `[ShoePair]` (an array of pairs of shoes). I leave it up to you to define the `Shoe` and `ShoePair` types. Remember each `Shoe` has a `style` and `foot`.

Hints:
There may be more than one valid pair of a single style.
Once a shoe has been used in a pair, it is not allowed to be apart of any other pair.
*/

struct Shoe {
  string style;
  string foot;
  Shoe(string style, string foot) : style(style), foot(foot) {}
};

struct ShoePair {
  Shoe* leftShoe;
  Shoe* rightShoe;
  ShoePair(Shoe* left, Shoe* right) : leftShoe(left), rightShoe(right) {}
};

// Runtime: O(n)
// Space: O(n)
vector<ShoePair> sortShoes(vector<Shoe>& shoes) {
  vector<ShoePair> retVal;
  map<string, stack<Shoe*>> shoeMap;
  for (int i = 0; i < (int)shoes.size(); i++) {
    string shoeKey = "" + shoes[i].style + shoes[i].foot;
    shoeMap[shoeKey].push(&shoes[i]); 
  }
  
  for (int i = 0; i < (int)shoes.size(); i++) {
    if (shoes[i].foot == "left") {
      if(!shoeMap[shoes[i].style + "right"].empty()) {
        Shoe* rightShoe = shoeMap[shoes[i].style + "right"].top();
        shoeMap[shoes[i].style + "right"].pop();
        ShoePair shoePair = ShoePair(&shoes[i], rightShoe);
        retVal.push_back(shoePair);
      }
    }
  }
  
  return retVal;
}
