#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using std::map,std::unordered_map,std::multimap,std::vector,std::string;
// unordered map >> map in speed, map ordered by keys
// often used for frequency/ checking/ sorting
// multimap : allow multiple same key-value pairs

void simple_maps(vector<int>& nums){

    unordered_map<int,int> nummap;
    map<int,int> idmap;
   
    for(int i{}; i<nums.size(); ++i){
        if(nummap[nums[i]] != 0) { std::cout << "duplicate found!\n"; }
        // number as key, freq as val
        nummap[nums[i]]++;

        // index as key, number as val
        idmap.emplace(i,nums[i]);
    }
}

void investment_mapping(int k, int w, vector<int>& profits, vector<int>& capital){
    int cap = w;
    multimap<int,int> projectmp;

    // capital as key , pure profit as value
    for(int i{}; i<profits.size(); i++){
        projectmp.insert({capital[i],profits[i]});
    }
    
    // k : max num of projects allowed to invest
    for(int j{}; j<k; j++){
        
        // find projects
        // assume higher capital higher profit

        // upper_bound(x) : find pairs with key <= x
        // lower_bound(x) : find pairs with key <= x
        int temp_key = projectmp.upper_bound(cap)->first; 

        // equal_range(y) : return it range for all pairs with key=y
        auto it = projectmp.equal_range(temp_key);

        int max_cap{};
        auto chosen_it = it.first;
        
        // loop projects possible with current capital
        // find projct with max profit
        for(auto itr=it.first; itr!=it.second; ++itr){
            if(itr->second > max_cap){
                max_cap = itr->second;
                chosen_it = itr;
            }
        }

        cap += chosen_it->second;
        projectmp.erase(chosen_it);

    }

    std::cout << "intial capital: " << w << '\n';
    std::cout << "final capital: " << cap << '\n';
    
}

struct AreaRecord
{
    int level;
    std::string species;
    std::vector<std::string> bosses;
};

// template specialisation for hashing
// if ur not using int/string as key but custom struct
namespace std {

    template<>
    struct hash<AreaRecord>
    {
        size_t operator()(const AreaRecord& key)
        {
            return hash<int>()(key.level);
        }
    };
}

void run_game_mapping()
{
    std::unordered_map<std::string,AreaRecord> gameMap;

    // inserting pairs
    gameMap.emplace("Frost Forest",AreaRecord{10,"misties",{"Noel"}});
    gameMap.emplace("Dark Abyss",AreaRecord{35,"shades",{"Knight","Headless"}});
    gameMap.emplace("Cloud Bay",AreaRecord{50,"fluffies",{"Lune","Mirage"}});
    gameMap.emplace("Choco Lava",AreaRecord{80,"churros",{"Marshmallow King"}});
    
    // accessing
    std::cout << "Level required to unlock 1st area: " << gameMap["Frost Forest"].level << std::endl;

    // find key exists
    std::string target_area = "Choco Lava";
    // std::cout << "Enter target area name: ";
    // std::cin >> target_area;
    std::cout << "Searching for " << target_area << "...\n";
    if(gameMap.find(target_area) != gameMap.end()){
        std::cout << target_area << " recorded in map.\n";
    } else{
        std::cout << target_area << " does not exist in map.\n";
    }

    // count function to check key exixts
    std::cout << "Counting for " << target_area << " existence: " << gameMap.count(target_area) << std::endl;

    // erasing data pair
    gameMap.erase("Choco Lava");
    std::cout << target_area << " removed from map.\n";

    // iterate through map
    std::cout << "\n\n~~~~~Current Map~~~~~ \n";
    for(auto& AreaRec:gameMap){
        std::cout << AreaRec.first << std::endl;
        std::cout << "Level : " << AreaRec.second.level << std::endl;
        std::cout << "NPCs : " << AreaRec.second.species << "\n\n";
    }

}
