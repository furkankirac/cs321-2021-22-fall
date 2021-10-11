#pragma once

template<typename T>
struct Vector
{
    static int n_vectors;

    int n_dims = 0;
    T* values = nullptr;

    // default c-tor
    Vector()
    {
        ++n_vectors;
    }

    Vector(int n_dims, T* values) : n_dims(n_dims), values(new T[n_dims])
    {
        ++n_vectors;
        if(values != nullptr)
            for(int i=0; i<n_dims; i++)
                this->values[i] = values[i];
    }

    ~Vector()
    {
        delete[] values;
        --n_vectors;
    }

    Vector<T> operator+(const Vector<T>& other) const // Generalized Return Value Optimization GRVO
    {
        Vector<T> result(n_dims, nullptr);
        if(n_dims != other.n_dims)
        {
            std::cout << "Number of dimensions don't hold" << std::endl;
            return result;
        }

        for(int i=0; i<n_dims; i++)
            result.values[i] = this->values[i] + other.values[i];

        return result;
    }
};

