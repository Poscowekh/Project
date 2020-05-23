// Graph.cpp for Model

#include "Graph.h"

using namespace std;
namespace GameModel
{
    Graph::Graph(size_t id, spMatrix mtrx)
    {
        matrix = mtrx;
        height = matrix->get_rows();
        width = matrix->get_columns();
        snakes_head = matrix->get_snakes()[matrix->return_snakes_index_by_id(id)].get_head();;
        for(size_t i = 0; i < matrix->get_food_count(); i++)
            food.push_back(make_pair(i, 0));
        if(height >= width)
            shift = height;
        else
            shift = width;
        infinity = shift * shift + 1;
        count = height * width;
        head_key = snakes_head.first + snakes_head.second * shift;
        create_map();
    }

    pair<size_t, size_t> Graph::get_initial_values(pair<size_t, size_t> coords)
    {
        size_t matrix_value = matrix->get_value(coords); //rework for terrain
        size_t in = 1;
        size_t out = 0;
        if((matrix_value == 8 ) || (matrix_value == 1) || (matrix_value == 3))
            in = infinity;
        return make_pair(in, out);
                       //Maybe add terrain types here later
    }

    void Graph::create_map()
    {
        for(size_t i = 0; i < height; i++)
            for(size_t j = 0; j < width; j++)
            {
                size_t tmp_key = shift * j + i;
                pair<size_t, size_t> values = get_initial_values(make_pair(i,j));
                Node tmp_node(make_pair(i,j), values.first, values.second, tmp_key);
                tmp_node.set_distance(infinity);
                nodes.insert(make_pair(tmp_key, tmp_node));
                set_neighbours(tmp_node.get_coordinates(), tmp_key);
            }
    }

    void Graph::print_graph()
    {
        for(size_t i = 0; i < height; i++)
        {
            for(size_t j = 0; j < width; j++)
            {
                size_t tmp_key = shift * j + i;
                size_t dist = nodes[tmp_key].get_neighbours_count();
                size_t val_in = nodes[tmp_key].get_values().first;
                cout << val_in << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    void Graph::print_keys()
    {
        for(size_t i = 0; i < height; i++)
        {
            for(size_t j = 0; j < width; j++)
            {
                size_t tmp_key = shift * j + i;
                if(tmp_key < 10)
                    cout << tmp_key << "  ";
                else
                    cout << tmp_key << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    size_t Graph::get_height()
    {
        return height;
    }

    size_t Graph::get_width()
    {
        return width;
    }

    size_t Graph::get_count()
    {
        return height * width;
    }

    void Graph::set_neighbours(pair<size_t, size_t> coords, size_t tmp_key)
    {
        if(coords.first + 1 < height)
            nodes[tmp_key].add_neighbour(tmp_key + shift);
        if(coords.first - 1 >= 0)
            nodes[tmp_key].add_neighbour(tmp_key - shift);
        if(coords.second + 1 < width)
            nodes[tmp_key].add_neighbour(tmp_key + 1);
        if(coords.second - 1 >= 0)
            nodes[tmp_key].add_neighbour(tmp_key - 1);
    }

    void Graph::count_from_node(Node* init_node)
    {
        if(init_node->get_values().first < infinity || init_node->get_key() == head_key)
        {
            recount_distance_to_node(init_node);
            recount_distance_to_neighbours(init_node);
            init_node->mark_as_visited();
            count_next_nodes(init_node);
        }
        else
            init_node->mark_as_visited();
    }

    void Graph::count_next_nodes(Node* init_node)
    {
        Node* tmp_node = new Node();
        vector< pair<size_t,size_t> > distance_vector;             // skeys neighbours
        for(size_t i = 0; i < init_node->get_neighbours_count(); i++)
        {
            size_t tmp_key = init_node->get_neighbours_keys()[i];
            tmp_node = &nodes[tmp_key];
            if(tmp_node->get_values().first < infinity)
                distance_vector.push_back(make_pair(tmp_key, tmp_node->get_distance()));
        }
        //distance_vector = sort_distance_vector(distance_vector);
        for(size_t i = 0; i < distance_vector.size(); i++)
        {
            tmp_node = &nodes[distance_vector[i].first];
            if(!(tmp_node->get_visit_flag()))
                count_from_node(tmp_node);
        }
        //delete tmp_node;
    }

    void Graph::recount_distance_to_node(Node* init_node)
    {   //Update init_node distance to lowest
        if(init_node->get_distance() > 0)
        {
            Node* tmp_node = new Node();
            size_t distance;
            for(size_t i = 0; i < init_node->get_neighbours_count(); i++)
            {
                size_t tmp_key = init_node->get_neighbours_keys()[i];
                tmp_node = &nodes[tmp_key];
                distance = tmp_node->get_distance() + init_node->get_values().first;
                if(distance < init_node->get_distance())
                    init_node->set_distance(distance);
            }
            //delete tmp_node;
        }
    }

    void Graph::recount_distance_to_neighbours(Node* init_node)
    {
        Node* tmp_node = new Node();
        size_t distance;
        size_t tmp_key;
        for(size_t i = 0; i < init_node->get_neighbours_count(); i++)
        {   //Update neighbours distances to lower if possible
            tmp_key = init_node->get_neighbours_keys()[i];
            tmp_node = &nodes[tmp_key];
            distance = init_node->get_distance() + tmp_node->get_values().first;
            if(distance < tmp_node->get_distance() && tmp_node->get_values().first < infinity)
                tmp_node->set_distance(distance);
        }
    }

    vector< pair<size_t, size_t> > Graph::sort_distance_vector(vector< pair<size_t, size_t> > vect)
    {
        for(size_t i = 0; i < vect.size(); i++)
            for(size_t j = 0; j < vect.size(); j++)
                if(vect[j].second < vect[i].second)
                {
                    pair<size_t, size_t> tmp = vect[i];
                    vect[j] = vect[i];
                    vect[i] = tmp;
                }
        return vect;
    }

    void Graph::print_distance()
    {
        cout << endl;
        cout << "/ ";
        for(size_t i = 0; i < matrix->get_columns(); i++)
            cout << i << ' ';
        cout << endl;
        for(size_t i = 0; i < height; i++)
        {
            cout << i << ' ';
            for(size_t j = 0; j < width; j++)
            {
                if(nodes[shift * j + i].get_distance() == infinity)
                    cout << "- ";
                else
                    cout << nodes[shift * j + i].get_distance() << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    void Graph::build_way(size_t food_key)
    {
        int check;
        bool flag = true;
        size_t tmp_key;
        tmp_key = food_key;
        if(nodes[food_key].get_distance() < infinity && flag)
            while(tmp_key != head_key)
            {
               way.push_back(tmp_key);
               tmp_key = choose_node(tmp_key);
               check++;
               if(check >= count)
                   flag = false;
            }
        else
            way.resize(0);
    }

    int Graph::choose_node(size_t key)
    {
        size_t next_key = key;
        size_t distance = nodes[key].get_distance();
        vector<size_t> neighbours = nodes[key].get_neighbours_keys();
        for(size_t i = 0; i < neighbours.size(); i++)
            if(nodes[neighbours[i]].get_distance() < distance)
            {
                next_key = neighbours[i];
                distance = nodes[next_key].get_distance();
            }
        return next_key;
    }

    void Graph::recheck_distances(Node* init_node)
    {
        recount_distance_to_neighbours(init_node);
        init_node->mark_as_visited();
        for(size_t i = 0; i < init_node->get_neighbours_count(); i++)
            if(!nodes[init_node->get_neighbours_keys()[i]].get_visit_flag())
                recheck_distances(&nodes[init_node->get_neighbours_keys()[i]]);
    };

    void Graph::unmark_nodes()
    {
        for(size_t i = 0; i < height; i++)
            for(size_t j = 0; j < width; j++)
            {
                size_t tmp_key = shift * j + i;
                nodes[tmp_key].unmark_as_visited();
            }
    }

    void Graph::Dijkstra()
    {
        nodes[head_key].set_distance(0);
        nodes[head_key].mark_as_visited();
        count_from_node(&nodes[head_key]);
        unmark_nodes();
        recheck_distances(&nodes[head_key]);
        size_t food_key = matrix->get_food()[0].get_coordinates().first +
                matrix->get_food()[0].get_coordinates().second * shift;
        if(nodes[food_key].get_distance() == infinity)
            way.resize(0);
        else
            build_way(food_key);
    }

    size_t Graph::get_distance()
    {
        size_t food_key = matrix->get_food()[0].get_coordinates().first + matrix->get_food()[0].get_coordinates().second * shift;
        return nodes[food_key].get_distance();
    }

    vector<size_t> Graph::get_way()
    {
        return way;
    }

    pair<size_t, size_t> Graph::get_coords(size_t key)
    {
        return make_pair(key % shift, key / shift);
    };

    pair<size_t, size_t> Graph::get_snake_head()
    {
        return snakes_head;
    };

    vector<size_t> Graph::safe_way(size_t diff_dist)
    {
        vector<size_t> tmp_keys;
        size_t max = 0;
        size_t max_index = 0;
        for(size_t i = 0; i < height; i++)
            for(size_t j = 0; j < width; j++)
            {
                size_t tmp_key = shift * j + i;
                if(matrix->get_value(get_coords(tmp_key)) == 0 && nodes[tmp_key].get_distance() >= diff_dist)
                    tmp_keys.push_back(tmp_key);
            };
        for(size_t i = 0; i < tmp_keys.size(); i++)
        {
            build_way(tmp_keys[i]);
            if(way.size() == 0)
            {
                tmp_keys[i] = tmp_keys[tmp_keys.size() - 1];
                tmp_keys.pop_back();
            }
            else
                if(way.size() > max)
                {
                    max = way.size();
                    max_index = i;
                };
        };
        if(tmp_keys.size() == 0 && diff_dist > 0)
        {
            diff_dist--;
            safe_way(diff_dist - 1);
        };
        if(max == 0)
        {
            way.resize(0);
        }
        else
            build_way(tmp_keys[max_index]);
        return way;
    };

    /*
    pair<size_t,size_t> Graph::any_move()
    {
        pair<size_t,size_t> tmp = make_pair(0,0);
        for(size_t i = 0; i < nodes[head_key].get_neighbours_count(); i++)
            if(matrix->get_value(get_coords(nodes[head_key].get_neighbours_keys()[i])) == 0)
                tmp = get_coords(nodes[head_key].get_neighbours_keys()[i]);
        return tmp;
    };
    */
}
