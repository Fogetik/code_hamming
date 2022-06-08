//
// Created by danil on 08.06.2022.
//

#ifndef L_2_CODE_HAMMING_H
#define L_2_CODE_HAMMING_H

int number_control_bit(int count){
    int help = 1, number;
    for(int i = 1;; i++){
        help *= 2;
        if(help == count){
            return help + i + 1;
        }else if(help > count)
            return 0;
    }
}

int number_without_control_bit(int count){
    int help = 1, i = 0;
    while(help < count){
        help *= 2;
        i++;
    }

    help /= 2;
    i--;
    if (help == count - i - 1)
        return help;
    else
        return 0;
}

int* code_hamming(int* array, int number){
    int after_number = number_control_bit(number);
    int degree_2 = 1, old_pos = 0, count_1;
    int *after_array = new int[after_number];
    bool f;
    for (int i = 0; i < after_number; i++){
        if (i + 1 == degree_2){
            degree_2 *= 2;
            after_array[i] = 0;
        }
        else{
            after_array[i] = array[old_pos++];
        }
    }

    degree_2 = 1;
    for(int i = 0; i < after_number - number; i++){
        old_pos = degree_2 - 1;
        count_1 = 0;
        f = true;
        while(old_pos < after_number){
            for (int a = 0; a < degree_2; a++){
                if (after_array[old_pos++] == 1)
                    count_1++;

                if (old_pos == after_number)
                    goto point;
            }

            for (int a = 0; a < degree_2; a++){
                old_pos++;
                if (old_pos == after_number)
                    goto point;
            }

        }
        point:
        after_array[degree_2-1] = count_1%2;
        degree_2 *= 2;
    }

    return after_array;
}

int* decoder(int* array, int number){
    int after_number = number_without_control_bit(number);
    int degree_2 = 1;
    int *after_array = new int[after_number], pos = 0;
    for(int i = 0; i < number; i++){
        if (i + 1 == degree_2){
            degree_2 *= 2;
        }
        else{
            after_array[pos++] = array[i];
        }
    }

    return after_array;
}

int check_exception(int* array, int number){
    int *array_copy = decoder(array, number);
    array_copy = code_hamming(array_copy, number_without_control_bit(number));
    int count = 0;
    int degree_2 = 1;
    while(degree_2-1 < number){
        if (array_copy[degree_2-1] != array[degree_2-1])
            count += degree_2;

        degree_2 *= 2;
    }

    return count;
}

#endif //L_2_CODE_HAMMING_H
