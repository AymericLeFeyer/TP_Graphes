function L = parcours(M, s)
    n = size(M)(1,1);       //  taille de la matrice
    pred = [];              //  liste des predecesseurs
    sommets_visites = [];   //  sommets visites
    A = zeros(n,n);         //  arcs visites
    
    while length(sommets_visites) < n
        sommets_visites = [sommets_visites s];                  //  mise a jour de la liste des sommet visites
        pred = [pred s];                                        //  le sommet s devient le predecesseur
        s1 = trouver_sommet(s, n, M, A, pred, length(pred));    //  parcours en profondeur
        A(s,s1) = 1;                                            //  mise a jour des arcs visites
        s = s1;                                                 //  mise a jour du sommet courant

    end
   L = [sommets_visites; pred];                                 // resultat final
endfunction


function s = trouver_sommet(sommet, n, M, A, pred, cnt)                                           
    
    i = 1;
    disp("sommet courant -> "+string(sommet))
    while (sommet == i | M(sommet,i) == 0 | A(sommet,i) == 1)   //  on cherche un sommet (arc) non-visite depuis le sommet s
        i = i + 1;      //  si c'est le meme sommet ou si il n'y a pas d'arc entre les deux sommets ou si on a deja visite l'arc -> passe au sommet suivant
        if i > n then break end
    end    

    if i > n then                                   
        disp("FINI AVEC SOMMET "+string(sommet));                                            // si tous les arcs sont deja visites, revient en arriere
        if cnt > 1 then
            cnt = cnt - 1;                                                          // visite le sommet precedant
            s = trouver_sommet(pred(cnt),n,M,A,pred,cnt);
        end
    else
        s = i;                                                                      // sinon on a trouve un nouveau sommet
    end
    

endfunction
