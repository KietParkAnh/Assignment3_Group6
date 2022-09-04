struct position_Handler{
    float x;
    float y;
    position_Handler(float x, float y){
        this->x = x;
        this->y = y;
    };
    position_Handler(){
        this->x = 0;
        this->y = 0;
    }
};

struct vector_Handler {
    position_Handler start;
    position_Handler end;
    
    float get_Distance(){
        position_Handler newVector = this->get_Vector();
        return sqrt(newVector.x*newVector.x + newVector.y*newVector.y);
    };
    position_Handler get_Vector(){
        float thisX = this->end.x - this->start.x;
        float thisY = this->end.y - this->start.y;
        position_Handler newVector(thisX ,thisY);
        return newVector;
    };
    // position_Handler add_Vector(){
    //     return
    // }
    vector_Handler(position_Handler start, position_Handler end){
        this->start = start;
        this->end = end;
    }
    position_Handler vector_Multiplier();
    vector_Handler get_ParallelX(float x){
        position_Handler newVector = this->get_Vector();
        newVector.x = newVector.x*abs(x/this->end.x);
        newVector.y = newVector.y*abs(x/this->end.x);
        vector_Handler newEnd(this->start, position_Handler(this->start.x+newVector.x,this->start.y+newVector.y));
        return newEnd;
    };
    vector_Handler get_ParallelY(float y){
        position_Handler newVector = this->get_Vector();
        newVector.x = newVector.x*abs(y/this->end.y);
        newVector.y = newVector.y*abs(y/this->end.y);
        vector_Handler newEnd(this->start, position_Handler(this->start.x+newVector.x,this->start.y+newVector.y));
        return newEnd;
    };
};


struct movement_Handler{
    vector_Handler movement;
    vector_Handler movement_Initial[100];
    vector_Handler movement_Final[100];
};

struct collision_check{
    
};