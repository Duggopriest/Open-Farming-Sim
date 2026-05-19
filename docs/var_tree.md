
// cause SDL_Texture doesent allow for arrays
Texture_Array
{
    SDL_Texture* texture;
}

Global var 
{
    int	Terrain_Seed;
    int	Airable_Seed;

    // stores all the Terrain textures
    Terrain_Base[255] {
        N/A     |       0       :
        N/A     |       1       :
        N/A     |       2       :
        N/A     |       3       :
        N/A     |       4       :
        N/A     |       5       :
        N/A     |       6       :
        N/A     |       7       :
        N/A     |       8       :
        N/A     |       9       :
        N/A     |       10      :
        N/A     |       11      :
        N/A     |       12      :
        N/A     |       13      :
        N/A     |       14      :
        N/A     |       15      :
        N/A     |       16      :
        N/A     |       17      :
        N/A     |       18      :
        N/A     |       19      :
        N/A     |       20      :
        N/A     |       21      :
        N/A     |       22      :
        N/A     |       23      :
        N/A     |       24      :
        N/A     |       25      :
        N/A     |       26      :
        N/A     |       27      :
        N/A     |       28      :
        N/A     |       29      :
        N/A     |       30      :
        N/A     |       31      :
                |       32      :
        !       |       33      :
        "       |       34      :
        #       |       35      :
        $       |       36      :
        %       |       37      :
        &       |       38      :
        '       |       39      :
        (       |       40      :
        )       |       41      :
        *       |       42      :
        +       |       43      :
        ,       |       44      :
        -       |       45      :
        .       |       46      :
        /       |       47      :
        0       |       48      :
        1       |       49      :
        2       |       50      :
        3       |       51      :
        4       |       52      :
        5       |       53      :
        6       |       54      :
        7       |       55      :
        8       |       56      :
        9       |       57      :
        :       |       58      :
        ;       |       59      :
        <       |       60      :
        =       |       61      :
        >       |       62      :
        ?       |       63      :
        @       |       64      :
        A       |       65      :
        B       |       66      :
        C       |       67      :
        D       |       68      :
        E       |       69      :
        F       |       70      :
        G       |       71      :
        H       |       72      :
        I       |       73      :
        J       |       74      :
        K       |       75      :
        L       |       76      :
        M       |       77      :
        N       |       78      :
        O       |       79      :
        P       |       80      :
        Q       |       81      :
        R       |       82      :
        S       |       83      :
        T       |       84      :
        U       |       85      :
        V       |       86      :
        W       |       87      :
        X       |       88      :
        Y       |       89      :
        Z       |       90      :
        [       |       91      :
        \       |       92      :
        ]       |       93      :
        ^       |       94      :
        _       |       95      :
        `       |       96      :
        a       |       97      :
        b       |       98      :
        c       |       99      :
        d       |       100     :
        e       |       101     :
        f       |       102     :
        g       |       103     :   g.bmp
        h       |       104     :
        i       |       105     :
        j       |       106     :
        k       |       107     :
        l       |       108     :
        m       |       109     :
        n       |       110     :
        o       |       111     :
        p       |       112     :
        q       |       113     :
        r       |       114     :   r.bmp
        s       |       115     :
        t       |       116     :   t.bmp
        u       |       117     :
        v       |       118     :
        w       |       119     :   w.bmp
        x       |       120     :
        y       |       121     :
        z       |       122     :
        {       |       123     :
        |       |       124     :
        }       |       125     :
        ~       |       126     :
        N/A     |       127     :
        N/A     |       128     :
        N/A     |       129     :
        N/A     |       130     :
        N/A     |       131     :
        N/A     |       132     :
        N/A     |       133     :
        N/A     |       134     :
        N/A     |       135     :
        N/A     |       136     :
        N/A     |       137     :
        N/A     |       138     :
        N/A     |       139     :
        N/A     |       140     :
        N/A     |       141     :
        N/A     |       142     :
        N/A     |       143     :
        N/A     |       144     :
        N/A     |       145     :
        N/A     |       146     :
        N/A     |       147     :
        N/A     |       148     :
        N/A     |       149     :
        N/A     |       150     :
        N/A     |       151     :
        N/A     |       152     :
        N/A     |       153     :
        N/A     |       154     :
        N/A     |       155     :
        N/A     |       156     :
        N/A     |       157     :
        N/A     |       158     :
        N/A     |       159     :
        N/A     |       160     :
        N/A     |       161     :
        N/A     |       162     :
        N/A     |       163     :
        N/A     |       164     :
        N/A     |       165     :
        N/A     |       166     :
        N/A     |       167     :
        N/A     |       168     :
        N/A     |       169     :
        N/A     |       170     :
        N/A     |       171     :
        N/A     |       172     :
        N/A     |       173     :
        N/A     |       174     :
        N/A     |       175     :
        N/A     |       176     :
        N/A     |       177     :
        N/A     |       178     :
        N/A     |       179     :
        N/A     |       180     :
        N/A     |       181     :
        N/A     |       182     :
        N/A     |       183     :
        N/A     |       184     :
        N/A     |       185     :
        N/A     |       186     :
        N/A     |       187     :
        N/A     |       188     :
        N/A     |       189     :
        N/A     |       190     :
        N/A     |       191     :
        N/A     |       192     :
        N/A     |       193     :
        N/A     |       194     :
        N/A     |       195     :
        N/A     |       196     :
        N/A     |       197     :
        N/A     |       198     :
        N/A     |       199     :
        N/A     |       200     :
        N/A     |       201     :
        N/A     |       202     :
        N/A     |       203     :
        N/A     |       204     :
        N/A     |       205     :
        N/A     |       206     :
        N/A     |       207     :
        N/A     |       208     :
        N/A     |       209     :
        N/A     |       210     :
        N/A     |       211     :
        N/A     |       212     :
        N/A     |       213     :
        N/A     |       214     :
        N/A     |       215     :
        N/A     |       216     :
        N/A     |       217     :
        N/A     |       218     :
        N/A     |       219     :
        N/A     |       220     :
        N/A     |       221     :
        N/A     |       222     :
        N/A     |       223     :
        N/A     |       224     :
        N/A     |       225     :
        N/A     |       226     :
        N/A     |       227     :
        N/A     |       228     :
        N/A     |       229     :
        N/A     |       230     :
        N/A     |       231     :
        N/A     |       232     :
        N/A     |       233     :
        N/A     |       234     :
        N/A     |       235     :
        N/A     |       236     :
        N/A     |       237     :
        N/A     |       238     :
        N/A     |       239     :
        N/A     |       240     :
        N/A     |       241     :
        N/A     |       242     :
        N/A     |       243     :
        N/A     |       244     :
        N/A     |       245     :
        N/A     |       246     :
        N/A     |       247     :
        N/A     |       248     :
        N/A     |       249     :
        N/A     |       250     :
        N/A     |       251     :
        N/A     |       252     :
        N/A     |       253     :
        N/A     |       254     :
    }

    // stores all the Building textures
    Building_Base[255] {
        N/A     |       0       :
        N/A     |       1       :
        N/A     |       2       :
        N/A     |       3       :
        N/A     |       4       :
        N/A     |       5       :
        N/A     |       6       :
        N/A     |       7       :
        N/A     |       8       :
        N/A     |       9       :
        N/A     |       10      :
        N/A     |       11      :
        N/A     |       12      :
        N/A     |       13      :
        N/A     |       14      :
        N/A     |       15      :
        N/A     |       16      :
        N/A     |       17      :
        N/A     |       18      :
        N/A     |       19      :
        N/A     |       20      :
        N/A     |       21      :
        N/A     |       22      :
        N/A     |       23      :
        N/A     |       24      :
        N/A     |       25      :
        N/A     |       26      :
        N/A     |       27      :
        N/A     |       28      :
        N/A     |       29      :
        N/A     |       30      :
        N/A     |       31      :
                |       32      :
        !       |       33      :
        "       |       34      :
        #       |       35      :
        $       |       36      :
        %       |       37      :
        &       |       38      :
        '       |       39      :
        (       |       40      :
        )       |       41      :
        *       |       42      :
        +       |       43      :
        ,       |       44      :
        -       |       45      :
        .       |       46      :
        /       |       47      :
        0       |       48      :
        1       |       49      :
        2       |       50      :
        3       |       51      :
        4       |       52      :
        5       |       53      :
        6       |       54      :
        7       |       55      :
        8       |       56      :
        9       |       57      :
        :       |       58      :
        ;       |       59      :
        <       |       60      :
        =       |       61      :
        >       |       62      :
        ?       |       63      :
        @       |       64      :
        A       |       65      :
        B       |       66      :
        C       |       67      :
        D       |       68      :
        E       |       69      :
        F       |       70      :
        G       |       71      :
        H       |       72      :
        I       |       73      :
        J       |       74      :
        K       |       75      :
        L       |       76      :
        M       |       77      :
        N       |       78      :
        O       |       79      :
        P       |       80      :
        Q       |       81      :
        R       |       82      :
        S       |       83      :
        T       |       84      :
        U       |       85      :
        V       |       86      :
        W       |       87      :
        X       |       88      :
        Y       |       89      :
        Z       |       90      :
        [       |       91      :
        \       |       92      :
        ]       |       93      :
        ^       |       94      :
        _       |       95      :
        `       |       96      :
        a       |       97      :
        b       |       98      :
        c       |       99      :
        d       |       100     :
        e       |       101     :
        f       |       102     :
        g       |       103     :
        h       |       104     :
        i       |       105     :
        j       |       106     :
        k       |       107     :
        l       |       108     :
        m       |       109     :
        n       |       110     :
        o       |       111     :
        p       |       112     :
        q       |       113     :
        r       |       114     :
        s       |       115     :
        t       |       116     :
        u       |       117     :
        v       |       118     :
        w       |       119     :
        x       |       120     :
        y       |       121     :
        z       |       122     :
        {       |       123     :
        |       |       124     :
        }       |       125     :
        ~       |       126     :
        N/A     |       127     :
        N/A     |       128     :
        N/A     |       129     :
        N/A     |       130     :
        N/A     |       131     :
        N/A     |       132     :
        N/A     |       133     :
        N/A     |       134     :
        N/A     |       135     :
        N/A     |       136     :
        N/A     |       137     :
        N/A     |       138     :
        N/A     |       139     :
        N/A     |       140     :
        N/A     |       141     :
        N/A     |       142     :
        N/A     |       143     :
        N/A     |       144     :
        N/A     |       145     :
        N/A     |       146     :
        N/A     |       147     :
        N/A     |       148     :
        N/A     |       149     :
        N/A     |       150     :
        N/A     |       151     :
        N/A     |       152     :
        N/A     |       153     :
        N/A     |       154     :
        N/A     |       155     :
        N/A     |       156     :
        N/A     |       157     :
        N/A     |       158     :
        N/A     |       159     :
        N/A     |       160     :
        N/A     |       161     :
        N/A     |       162     :
        N/A     |       163     :
        N/A     |       164     :
        N/A     |       165     :
        N/A     |       166     :
        N/A     |       167     :
        N/A     |       168     :
        N/A     |       169     :
        N/A     |       170     :
        N/A     |       171     :
        N/A     |       172     :
        N/A     |       173     :
        N/A     |       174     :
        N/A     |       175     :
        N/A     |       176     :
        N/A     |       177     :
        N/A     |       178     :
        N/A     |       179     :
        N/A     |       180     :
        N/A     |       181     :
        N/A     |       182     :
        N/A     |       183     :
        N/A     |       184     :
        N/A     |       185     :
        N/A     |       186     :
        N/A     |       187     :
        N/A     |       188     :
        N/A     |       189     :
        N/A     |       190     :
        N/A     |       191     :
        N/A     |       192     :
        N/A     |       193     :
        N/A     |       194     :
        N/A     |       195     :
        N/A     |       196     :
        N/A     |       197     :
        N/A     |       198     :
        N/A     |       199     :
        N/A     |       200     :
        N/A     |       201     :
        N/A     |       202     :
        N/A     |       203     :
        N/A     |       204     :
        N/A     |       205     :
        N/A     |       206     :
        N/A     |       207     :
        N/A     |       208     :
        N/A     |       209     :
        N/A     |       210     :
        N/A     |       211     :
        N/A     |       212     :
        N/A     |       213     :
        N/A     |       214     :
        N/A     |       215     :
        N/A     |       216     :
        N/A     |       217     :
        N/A     |       218     :
        N/A     |       219     :
        N/A     |       220     :
        N/A     |       221     :
        N/A     |       222     :
        N/A     |       223     :
        N/A     |       224     :
        N/A     |       225     :
        N/A     |       226     :
        N/A     |       227     :
        N/A     |       228     :
        N/A     |       229     :
        N/A     |       230     :
        N/A     |       231     :
        N/A     |       232     :
        N/A     |       233     :
        N/A     |       234     :
        N/A     |       235     :
        N/A     |       236     :
        N/A     |       237     :
        N/A     |       238     :
        N/A     |       239     :
        N/A     |       240     :
        N/A     |       241     :
        N/A     |       242     :
        N/A     |       243     :
        N/A     |       244     :
        N/A     |       245     :
        N/A     |       246     :
        N/A     |       247     :
        N/A     |       248     :
        N/A     |       249     :
        N/A     |       250     :
        N/A     |       251     :
        N/A     |       252     :
        N/A     |       253     :
        N/A     |       254     :
    }

    // stores all the Plant textures
    Plant_Base[255] {
        N/A     |       0       :   plowed.bmp
        N/A     |       1       :   wheat_1.bmp
        N/A     |       2       :   wheat_2.bmp
        N/A     |       3       :   wheat_3.bmp
        N/A     |       4       :   wheat_4.bmp
        N/A     |       5       :
        N/A     |       6       :
        N/A     |       7       :
        N/A     |       8       :
        N/A     |       9       :
        N/A     |       10      :
        N/A     |       11      :
        N/A     |       12      :
        N/A     |       13      :
        N/A     |       14      :
        N/A     |       15      :
        N/A     |       16      :
        N/A     |       17      :
        N/A     |       18      :
        N/A     |       19      :
        N/A     |       20      :
        N/A     |       21      :
        N/A     |       22      :
        N/A     |       23      :
        N/A     |       24      :
        N/A     |       25      :
        N/A     |       26      :
        N/A     |       27      :
        N/A     |       28      :
        N/A     |       29      :
        N/A     |       30      :
        N/A     |       31      :
                |       32      :
        !       |       33      :
        "       |       34      :
        #       |       35      :
        $       |       36      :
        %       |       37      :
        &       |       38      :
        '       |       39      :
        (       |       40      :
        )       |       41      :
        *       |       42      :
        +       |       43      :
        ,       |       44      :
        -       |       45      :
        .       |       46      :
        /       |       47      :
        0       |       48      :
        1       |       49      :
        2       |       50      :
        3       |       51      :
        4       |       52      :
        5       |       53      :
        6       |       54      :
        7       |       55      :
        8       |       56      :
        9       |       57      :
        :       |       58      :
        ;       |       59      :
        <       |       60      :
        =       |       61      :
        >       |       62      :
        ?       |       63      :
        @       |       64      :
        A       |       65      :
        B       |       66      :
        C       |       67      :
        D       |       68      :
        E       |       69      :
        F       |       70      :
        G       |       71      :
        H       |       72      :
        I       |       73      :
        J       |       74      :
        K       |       75      :
        L       |       76      :
        M       |       77      :
        N       |       78      :
        O       |       79      :
        P       |       80      :
        Q       |       81      :
        R       |       82      :
        S       |       83      :
        T       |       84      :
        U       |       85      :
        V       |       86      :
        W       |       87      :
        X       |       88      :
        Y       |       89      :
        Z       |       90      :
        [       |       91      :
        \       |       92      :
        ]       |       93      :
        ^       |       94      :
        _       |       95      :
        `       |       96      :
        a       |       97      :
        b       |       98      :
        c       |       99      :
        d       |       100     :
        e       |       101     :
        f       |       102     :
        g       |       103     :   
        h       |       104     :
        i       |       105     :
        j       |       106     :
        k       |       107     :
        l       |       108     :
        m       |       109     :
        n       |       110     :
        o       |       111     :
        p       |       112     :
        q       |       113     :
        r       |       114     :   
        s       |       115     :
        t       |       116     :   
        u       |       117     :
        v       |       118     :
        w       |       119     :   
        x       |       120     :
        y       |       121     :
        z       |       122     :
        {       |       123     :
        |       |       124     :
        }       |       125     :
        ~       |       126     :
        N/A     |       127     :
        N/A     |       128     :
        N/A     |       129     :
        N/A     |       130     :
        N/A     |       131     :
        N/A     |       132     :
        N/A     |       133     :
        N/A     |       134     :
        N/A     |       135     :
        N/A     |       136     :
        N/A     |       137     :
        N/A     |       138     :
        N/A     |       139     :
        N/A     |       140     :
        N/A     |       141     :
        N/A     |       142     :
        N/A     |       143     :
        N/A     |       144     :
        N/A     |       145     :
        N/A     |       146     :
        N/A     |       147     :
        N/A     |       148     :
        N/A     |       149     :
        N/A     |       150     :
        N/A     |       151     :
        N/A     |       152     :
        N/A     |       153     :
        N/A     |       154     :
        N/A     |       155     :
        N/A     |       156     :
        N/A     |       157     :
        N/A     |       158     :
        N/A     |       159     :
        N/A     |       160     :
        N/A     |       161     :
        N/A     |       162     :
        N/A     |       163     :
        N/A     |       164     :
        N/A     |       165     :
        N/A     |       166     :
        N/A     |       167     :
        N/A     |       168     :
        N/A     |       169     :
        N/A     |       170     :
        N/A     |       171     :
        N/A     |       172     :
        N/A     |       173     :
        N/A     |       174     :
        N/A     |       175     :
        N/A     |       176     :
        N/A     |       177     :
        N/A     |       178     :
        N/A     |       179     :
        N/A     |       180     :
        N/A     |       181     :
        N/A     |       182     :
        N/A     |       183     :
        N/A     |       184     :
        N/A     |       185     :
        N/A     |       186     :
        N/A     |       187     :
        N/A     |       188     :
        N/A     |       189     :
        N/A     |       190     :
        N/A     |       191     :
        N/A     |       192     :
        N/A     |       193     :
        N/A     |       194     :
        N/A     |       195     :
        N/A     |       196     :
        N/A     |       197     :
        N/A     |       198     :
        N/A     |       199     :
        N/A     |       200     :
        N/A     |       201     :
        N/A     |       202     :
        N/A     |       203     :
        N/A     |       204     :
        N/A     |       205     :
        N/A     |       206     :
        N/A     |       207     :
        N/A     |       208     :
        N/A     |       209     :
        N/A     |       210     :
        N/A     |       211     :
        N/A     |       212     :
        N/A     |       213     :
        N/A     |       214     :
        N/A     |       215     :
        N/A     |       216     :
        N/A     |       217     :
        N/A     |       218     :
        N/A     |       219     :
        N/A     |       220     :
        N/A     |       221     :
        N/A     |       222     :
        N/A     |       223     :
        N/A     |       224     :
        N/A     |       225     :
        N/A     |       226     :
        N/A     |       227     :
        N/A     |       228     :
        N/A     |       229     :
        N/A     |       230     :
        N/A     |       231     :
        N/A     |       232     :
        N/A     |       233     :
        N/A     |       234     :
        N/A     |       235     :
        N/A     |       236     :
        N/A     |       237     :
        N/A     |       238     :
        N/A     |       239     :
        N/A     |       240     :
        N/A     |       241     :
        N/A     |       242     :
        N/A     |       243     :
        N/A     |       244     :
        N/A     |       245     :
        N/A     |       246     :
        N/A     |       247     :
        N/A     |       248     :
        N/A     |       249     :
        N/A     |       250     :
        N/A     |       251     :
        N/A     |       252     :
        N/A     |       253     :
        N/A     |       254     :
    }

    // stores all the Player textures
    Player_Base[255] {
        N/A     |       0       :
        N/A     |       1       :   p.bmp
    }

    // stores the Chunks into a hash table
    std::map <int, std::map < int, Chunk > > ChunkMap;

    // stores the player data
    Player player;

    // sets the font style and size for the text
    static const char* FONT_NAME = "font.ttf";
    static const int FONT_SIZE = 20;

    // stores the Window Resolution values
    const int WINDOW_WIDTH, WINDOW_HEIGHT;


    // SDL verables
    SDL_Event event;
    SDL_Renderer* renderer;
    SDL_Window* window;

    // stores the current zoom level
    float ZOOM = 50;
}

Map
{
    // stores Current Chunk cords
    int CCx;
	int CCy;

    // map is loaded for loading screen;
	bool	loaded;
}

Player
{
    // stores player cords
    int	x;
	int	y;

    // stores current angle
	double angle;
}

Chunk
{
    unsigned char terrain[100][100];    // stores a generated terrain map
	unsigned char airable[100][100];    // stores generated airability map. used for calculating plant growth
	unsigned char fert[100][100];       // stores generated airability map. used for calculating plant growth
	unsigned char hydro[100][100];      // stores generated airability map. used for calculating plant growth
	unsigned char plowed[100][100];     // stores generated airability map. used to see if planting plants is possable. also meaby for calculating plant growth
	unsigned char buildings[100][100];  // stores building placed. gets priority over terrain for texture;

    // will only try and render/save buildings/plowed if there were any edits
	bool edited;

    // used to tell if chunk is already on ram or not. will first scan files if null then generate a new chunk
	bool loaded;

    // stores current spot in ChunkMap
	int x;
	int y;

    // stores cords
	int px;
	int py;

    // holds a array of what to draw
	Texture_Array textures[100][100];
}

Plant
{
    unsigned char	m_type;             // base select for textures
	unsigned char	m_maxGrowth;        // sets when plant is done growing
	unsigned char	m_currentGrowth;    // keeps track of current growth. cant go over max growth
}

inherits from plant
{
    Wheat
    {
        m_type              = 1;
	    m_maxGrowth         = 10;
	    m_currentGrowth     = 0;
    }
}



ITEM ID's
{
        N/A     |       0       :   Empty Item
        N/A     |       1       :   Plow_Item
        N/A     |       2       :   Scythe_Item
        N/A     |       3       :
        N/A     |       4       :
        N/A     |       5       :
        N/A     |       6       :
        N/A     |       7       :
        N/A     |       8       :
        N/A     |       9       :
        N/A     |       10      :
        N/A     |       11      :
        N/A     |       12      :
        N/A     |       13      :
        N/A     |       14      :
        N/A     |       15      :
        N/A     |       16      :
        N/A     |       17      :
        N/A     |       18      :
        N/A     |       19      :
        N/A     |       20      :   Wheat_Seed_Item
        N/A     |       21      :
        N/A     |       22      :
        N/A     |       23      :
        N/A     |       24      :
        N/A     |       25      :
        N/A     |       26      :
        N/A     |       27      :
        N/A     |       28      :
        N/A     |       29      :
        N/A     |       30      :
        N/A     |       31      :
                |       32      :
        !       |       33      :
        "       |       34      :
        #       |       35      :
        $       |       36      :
        %       |       37      :
        &       |       38      :
        '       |       39      :
        (       |       40      :   Wheat_Item
        )       |       41      :
        *       |       42      :
        +       |       43      :
        ,       |       44      :
        -       |       45      :
        .       |       46      :
        /       |       47      :
        0       |       48      :
        1       |       49      :
        2       |       50      :
        3       |       51      :
        4       |       52      :
        5       |       53      :
        6       |       54      :
        7       |       55      :
        8       |       56      :
        9       |       57      :
        :       |       58      :
        ;       |       59      :
        <       |       60      :
        =       |       61      :
        >       |       62      :
        ?       |       63      :
        @       |       64      :
        A       |       65      :
        B       |       66      :
        C       |       67      :
        D       |       68      :
        E       |       69      :
        F       |       70      :
        G       |       71      :
        H       |       72      :
        I       |       73      :
        J       |       74      :
        K       |       75      :
        L       |       76      :
        M       |       77      :
        N       |       78      :
        O       |       79      :
        P       |       80      :
        Q       |       81      :
        R       |       82      :
        S       |       83      :
        T       |       84      :
        U       |       85      :
        V       |       86      :
        W       |       87      :
        X       |       88      :
        Y       |       89      :
        Z       |       90      :
        [       |       91      :
        \       |       92      :
        ]       |       93      :
        ^       |       94      :
        _       |       95      :
        `       |       96      :
        a       |       97      :
        b       |       98      :
        c       |       99      :
        d       |       100     :
        e       |       101     :
        f       |       102     :
        g       |       103     :   g.bmp
        h       |       104     :
        i       |       105     :
        j       |       106     :
        k       |       107     :
        l       |       108     :
        m       |       109     :
        n       |       110     :
        o       |       111     :
        p       |       112     :
        q       |       113     :
        r       |       114     :   r.bmp
        s       |       115     :
        t       |       116     :   t.bmp
        u       |       117     :
        v       |       118     :
        w       |       119     :   w.bmp
        x       |       120     :
        y       |       121     :
        z       |       122     :
        {       |       123     :
        |       |       124     :
        }       |       125     :
        ~       |       126     :
        N/A     |       127     :
        N/A     |       128     :
        N/A     |       129     :
        N/A     |       130     :
        N/A     |       131     :
        N/A     |       132     :
        N/A     |       133     :
        N/A     |       134     :
        N/A     |       135     :
        N/A     |       136     :
        N/A     |       137     :
        N/A     |       138     :
        N/A     |       139     :
        N/A     |       140     :
        N/A     |       141     :
        N/A     |       142     :
        N/A     |       143     :
        N/A     |       144     :
        N/A     |       145     :
        N/A     |       146     :
        N/A     |       147     :
        N/A     |       148     :
        N/A     |       149     :
        N/A     |       150     :
        N/A     |       151     :
        N/A     |       152     :
        N/A     |       153     :
        N/A     |       154     :
        N/A     |       155     :
        N/A     |       156     :
        N/A     |       157     :
        N/A     |       158     :
        N/A     |       159     :
        N/A     |       160     :
        N/A     |       161     :
        N/A     |       162     :
        N/A     |       163     :
        N/A     |       164     :
        N/A     |       165     :
        N/A     |       166     :
        N/A     |       167     :
        N/A     |       168     :
        N/A     |       169     :
        N/A     |       170     :
        N/A     |       171     :
        N/A     |       172     :
        N/A     |       173     :
        N/A     |       174     :
        N/A     |       175     :
        N/A     |       176     :
        N/A     |       177     :
        N/A     |       178     :
        N/A     |       179     :
        N/A     |       180     :
        N/A     |       181     :
        N/A     |       182     :
        N/A     |       183     :
        N/A     |       184     :
        N/A     |       185     :
        N/A     |       186     :
        N/A     |       187     :
        N/A     |       188     :
        N/A     |       189     :
        N/A     |       190     :
        N/A     |       191     :
        N/A     |       192     :
        N/A     |       193     :
        N/A     |       194     :
        N/A     |       195     :
        N/A     |       196     :
        N/A     |       197     :
        N/A     |       198     :
        N/A     |       199     :
        N/A     |       200     :
        N/A     |       201     :
        N/A     |       202     :
        N/A     |       203     :
        N/A     |       204     :
        N/A     |       205     :
        N/A     |       206     :
        N/A     |       207     :
        N/A     |       208     :
        N/A     |       209     :
        N/A     |       210     :
        N/A     |       211     :
        N/A     |       212     :
        N/A     |       213     :
        N/A     |       214     :
        N/A     |       215     :
        N/A     |       216     :
        N/A     |       217     :
        N/A     |       218     :
        N/A     |       219     :
        N/A     |       220     :
        N/A     |       221     :
        N/A     |       222     :
        N/A     |       223     :
        N/A     |       224     :
        N/A     |       225     :
        N/A     |       226     :
        N/A     |       227     :
        N/A     |       228     :
        N/A     |       229     :
        N/A     |       230     :
        N/A     |       231     :
        N/A     |       232     :
        N/A     |       233     :
        N/A     |       234     :
        N/A     |       235     :
        N/A     |       236     :
        N/A     |       237     :
        N/A     |       238     :
        N/A     |       239     :
        N/A     |       240     :
        N/A     |       241     :
        N/A     |       242     :
        N/A     |       243     :
        N/A     |       244     :
        N/A     |       245     :
        N/A     |       246     :
        N/A     |       247     :
        N/A     |       248     :
        N/A     |       249     :
        N/A     |       250     :
        N/A     |       251     :
        N/A     |       252     :
        N/A     |       253     :
        N/A     |       254     :
}

PLANT ID's
{
        N/A     |       0       :   Empty Plant
        N/A     |       1       :   Wheat
        N/A     |       2       :   
        N/A     |       3       :
        N/A     |       4       :
        N/A     |       5       :
        N/A     |       6       :
        N/A     |       7       :
        N/A     |       8       :
        N/A     |       9       :
        N/A     |       10      :
        N/A     |       11      :
        N/A     |       12      :
        N/A     |       13      :
        N/A     |       14      :
        N/A     |       15      :
        N/A     |       16      :
        N/A     |       17      :
        N/A     |       18      :
        N/A     |       19      :
        N/A     |       20      :   Wheat_Seed_Item
        N/A     |       21      :
        N/A     |       22      :
        N/A     |       23      :
        N/A     |       24      :
        N/A     |       25      :
        N/A     |       26      :
        N/A     |       27      :
        N/A     |       28      :
        N/A     |       29      :
        N/A     |       30      :
        N/A     |       31      :
                |       32      :
        !       |       33      :
        "       |       34      :
        #       |       35      :
        $       |       36      :
        %       |       37      :
        &       |       38      :
        '       |       39      :
        (       |       40      :   Wheat_Item
        )       |       41      :
        *       |       42      :
        +       |       43      :
        ,       |       44      :
        -       |       45      :
        .       |       46      :
        /       |       47      :
        0       |       48      :
        1       |       49      :
        2       |       50      :
        3       |       51      :
        4       |       52      :
        5       |       53      :
        6       |       54      :
        7       |       55      :
        8       |       56      :
        9       |       57      :
        :       |       58      :
        ;       |       59      :
        <       |       60      :
        =       |       61      :
        >       |       62      :
        ?       |       63      :
        @       |       64      :
        A       |       65      :
        B       |       66      :
        C       |       67      :
        D       |       68      :
        E       |       69      :
        F       |       70      :
        G       |       71      :
        H       |       72      :
        I       |       73      :
        J       |       74      :
        K       |       75      :
        L       |       76      :
        M       |       77      :
        N       |       78      :
        O       |       79      :
        P       |       80      :
        Q       |       81      :
        R       |       82      :
        S       |       83      :
        T       |       84      :
        U       |       85      :
        V       |       86      :
        W       |       87      :
        X       |       88      :
        Y       |       89      :
        Z       |       90      :
        [       |       91      :
        \       |       92      :
        ]       |       93      :
        ^       |       94      :
        _       |       95      :
        `       |       96      :
        a       |       97      :
        b       |       98      :
        c       |       99      :
        d       |       100     :
        e       |       101     :
        f       |       102     :
        g       |       103     :   g.bmp
        h       |       104     :
        i       |       105     :
        j       |       106     :
        k       |       107     :
        l       |       108     :
        m       |       109     :
        n       |       110     :
        o       |       111     :
        p       |       112     :
        q       |       113     :
        r       |       114     :   r.bmp
        s       |       115     :
        t       |       116     :   t.bmp
        u       |       117     :
        v       |       118     :
        w       |       119     :   w.bmp
        x       |       120     :
        y       |       121     :
        z       |       122     :
        {       |       123     :
        |       |       124     :
        }       |       125     :
        ~       |       126     :
        N/A     |       127     :
        N/A     |       128     :
        N/A     |       129     :
        N/A     |       130     :
        N/A     |       131     :
        N/A     |       132     :
        N/A     |       133     :
        N/A     |       134     :
        N/A     |       135     :
        N/A     |       136     :
        N/A     |       137     :
        N/A     |       138     :
        N/A     |       139     :
        N/A     |       140     :
        N/A     |       141     :
        N/A     |       142     :
        N/A     |       143     :
        N/A     |       144     :
        N/A     |       145     :
        N/A     |       146     :
        N/A     |       147     :
        N/A     |       148     :
        N/A     |       149     :
        N/A     |       150     :
        N/A     |       151     :
        N/A     |       152     :
        N/A     |       153     :
        N/A     |       154     :
        N/A     |       155     :
        N/A     |       156     :
        N/A     |       157     :
        N/A     |       158     :
        N/A     |       159     :
        N/A     |       160     :
        N/A     |       161     :
        N/A     |       162     :
        N/A     |       163     :
        N/A     |       164     :
        N/A     |       165     :
        N/A     |       166     :
        N/A     |       167     :
        N/A     |       168     :
        N/A     |       169     :
        N/A     |       170     :
        N/A     |       171     :
        N/A     |       172     :
        N/A     |       173     :
        N/A     |       174     :
        N/A     |       175     :
        N/A     |       176     :
        N/A     |       177     :
        N/A     |       178     :
        N/A     |       179     :
        N/A     |       180     :
        N/A     |       181     :
        N/A     |       182     :
        N/A     |       183     :
        N/A     |       184     :
        N/A     |       185     :
        N/A     |       186     :
        N/A     |       187     :
        N/A     |       188     :
        N/A     |       189     :
        N/A     |       190     :
        N/A     |       191     :
        N/A     |       192     :
        N/A     |       193     :
        N/A     |       194     :
        N/A     |       195     :
        N/A     |       196     :
        N/A     |       197     :
        N/A     |       198     :
        N/A     |       199     :
        N/A     |       200     :
        N/A     |       201     :
        N/A     |       202     :
        N/A     |       203     :
        N/A     |       204     :
        N/A     |       205     :
        N/A     |       206     :
        N/A     |       207     :
        N/A     |       208     :
        N/A     |       209     :
        N/A     |       210     :
        N/A     |       211     :
        N/A     |       212     :
        N/A     |       213     :
        N/A     |       214     :
        N/A     |       215     :
        N/A     |       216     :
        N/A     |       217     :
        N/A     |       218     :
        N/A     |       219     :
        N/A     |       220     :
        N/A     |       221     :
        N/A     |       222     :
        N/A     |       223     :
        N/A     |       224     :
        N/A     |       225     :
        N/A     |       226     :
        N/A     |       227     :
        N/A     |       228     :
        N/A     |       229     :
        N/A     |       230     :
        N/A     |       231     :
        N/A     |       232     :
        N/A     |       233     :
        N/A     |       234     :
        N/A     |       235     :
        N/A     |       236     :
        N/A     |       237     :
        N/A     |       238     :
        N/A     |       239     :
        N/A     |       240     :
        N/A     |       241     :
        N/A     |       242     :
        N/A     |       243     :
        N/A     |       244     :
        N/A     |       245     :
        N/A     |       246     :
        N/A     |       247     :
        N/A     |       248     :
        N/A     |       249     :
        N/A     |       250     :
        N/A     |       251     :
        N/A     |       252     :
        N/A     |       253     :
        N/A     |       254     :
}