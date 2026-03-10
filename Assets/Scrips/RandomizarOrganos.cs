using System.Collections.Generic;
using UnityEngine;

public class RandomizarOrganos : MonoBehaviour
{
    void Start()
    {
        MezclarHijos();
    }

    void MezclarHijos()
    {
        List<Transform> hijos = new List<Transform>();

        foreach (Transform hijo in transform)
        {
            hijos.Add(hijo);
        }

        
        for (int i = hijos.Count - 1; i > 0; i--)
        {
            int j = Random.Range(0, i + 1);
            (hijos[i], hijos[j]) = (hijos[j], hijos[i]);
        }

        
        for (int i = 0; i < hijos.Count; i++)
        {
            hijos[i].SetSiblingIndex(i);
        }
    }
}