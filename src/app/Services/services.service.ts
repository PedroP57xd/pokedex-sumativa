import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';


@Injectable({
  providedIn: 'root'
})
export class ServicesService {
  private apiUrl = 'https://pokeapi.co/api/v2/';
  constructor(private http: HttpClient) { }


  getPokemonID(id: number): Observable<any> {
    return this.http.get(this.apiUrl + "pokemon/" + id);
  }

  getPokemonName(name: string): Observable<any> {
    return this.http.get(this.apiUrl + "pokemon/" + name);
  }

   getPokemonType(type: number): Observable<any> {
    return this.http.get(this.apiUrl + "type/" + type);
  }
  
}
