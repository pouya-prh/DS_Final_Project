#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class CompressedTrie {
public:
    std::unordered_map<char, CompressedTrie*> nodes;
    std::string prefix;
    bool is_leaf;

    CompressedTrie(const std::string& prefix = "", bool is_leaf = false)
        : prefix(prefix), is_leaf(is_leaf) {}

    std::tuple<std::string, std::string, std::string> match(const std::string& word) {
        size_t x = 0;
        for (size_t i = 0; i < prefix.size() && i < word.size(); ++i) {
            if (prefix[i] != word[i]) break;
            x++;
        }
        return { prefix.substr(0, x), prefix.substr(x), word.substr(x) };
    }

    void insert_many(const std::vector<std::string>& words) {
        for (const auto& word : words) {
            insert(word);
        }
    }

    void insert(const std::string& word) {
        if (prefix == word && !is_leaf) {
            is_leaf = true;
            return;
        }

        if (nodes.find(word[0]) == nodes.end()) {
            nodes[word[0]] = new CompressedTrie(word, true);
            return;
        }

        CompressedTrie* incoming_node = nodes[word[0]];
        std::tuple<std::string, std::string, std::string> result = incoming_node->match(word);
        std::string matching_string = std::get<0>(result);
        std::string remaining_prefix = std::get<1>(result);
        std::string remaining_word = std::get<2>(result);

        if (remaining_prefix.empty()) {
            incoming_node->insert(remaining_word);
        }
        else {
            incoming_node->prefix = remaining_prefix;

            CompressedTrie* aux_node = nodes[matching_string[0]];
            nodes[matching_string[0]] = new CompressedTrie(matching_string, false);
            nodes[matching_string[0]]->nodes[remaining_prefix[0]] = aux_node;

            if (remaining_word.empty()) {
                nodes[matching_string[0]]->is_leaf = true;
            }
            else {
                nodes[matching_string[0]]->insert(remaining_word);
            }
        }
    }

    bool find(const std::string& word) {
        auto it = nodes.find(word[0]);
        if (it == nodes.end()) return false;

        std::tuple<std::string, std::string, std::string> result = it->second->match(word);
        std::string matching_string = std::get<0>(result);
        std::string remaining_prefix = std::get<1>(result);
        std::string remaining_word = std::get<2>(result);

        if (!remaining_prefix.empty()) return false;

        if (remaining_word.empty()) return it->second->is_leaf;

        return it->second->find(remaining_word);
    }

    bool delete_word(const std::string& word) {
        auto it = nodes.find(word[0]);
        if (it == nodes.end()) return false;

        //auto [matching_string, remaining_prefix, remaining_word] = it->second->match(word);
        std::tuple<std::string, std::string, std::string> result = it->second->match(word);
        std::string matching_string = std::get<0>(result);
        std::string remaining_prefix = std::get<1>(result);
        std::string remaining_word = std::get<2>(result);

        if (!remaining_prefix.empty())
            return false;

        if (!remaining_word.empty()) {
            return it->second->delete_word(remaining_word);
        }

        if (!it->second->is_leaf)
            return false;

        if (it->second->nodes.empty()) {
            delete it->second;
            nodes.erase(it);

            if (nodes.size() == 1 && !is_leaf) {
                CompressedTrie* merging_node = nodes.begin()->second;
                is_leaf = merging_node->is_leaf;
                prefix += merging_node->prefix;
                nodes = std::move(merging_node->nodes);
                delete merging_node;
            }
        }
        else if (it->second->nodes.size() > 1) {
            it->second->is_leaf = false;
        }
        else {
            CompressedTrie* merging_node = it->second->nodes.begin()->second;
            it->second->is_leaf = merging_node->is_leaf;
            it->second->prefix += merging_node->prefix;
            it->second->nodes = std::move(merging_node->nodes);
            delete merging_node;
        }

        return true;
    }

    void print_tree(int height = 0) const {
        if (!prefix.empty()) {
            std::cout << std::string(height, '-') << " " << prefix
                << (is_leaf ? "  (leaf)" : "") << "\n";
        }

        for (const auto& pair : nodes) {
            pair.second->print_tree(height + 1);
        }
    }
};
