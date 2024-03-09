import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { RouteReuseStrategy } from '@angular/router';
import { initializeApp, provideFirebaseApp } from '@angular/fire/app';
import { getFirestore, provideFirestore } from '@angular/fire/firestore';
import { AngularFirestoreModule } from '@angular/fire/compat/firestore'; 
import { IonicModule, IonicRouteStrategy } from '@ionic/angular';
import { environment } from '../environments/environment'; // Importa el entorno
import { HttpClientModule } from '@angular/common/http';
import { AppComponent } from './app.component';
import { AppRoutingModule } from './app-routing.module';



@NgModule({
  declarations: [AppComponent],
  imports: [BrowserModule, IonicModule.forRoot(), AppRoutingModule,HttpClientModule, AngularFirestoreModule,
    provideFirebaseApp(() => initializeApp(environment.firebaseConfig)),
    provideFirestore(() => getFirestore()),
    provideFirebaseApp(() => initializeApp({"projectId":"pokedex-74590","appId":"1:426256829475:web:17fed0786d5992b4947596","storageBucket":"pokedex-74590.appspot.com","apiKey":"AIzaSyAwvibsko1t0NL8WHqO_LCOukzZZI2a1ZU","authDomain":"pokedex-74590.firebaseapp.com","messagingSenderId":"426256829475"})),],
providers: [{ provide: RouteReuseStrategy, useClass: IonicRouteStrategy }],
bootstrap: [AppComponent],
})
export class AppModule {}
