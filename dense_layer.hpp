/********************************************************************************
* dense_layer.hpp: Inneh�ller funktionalitet f�r implementering av dense-lager
*                  i neurala n�tverk (dolda lager och utg�ngslager) via
*                  strukten dense_layer.
********************************************************************************/
#ifndef DENSE_LAYER_HPP_
#define DENSE_LAYER_HPP_

/* Inkluderingsdirektiv: */
#include <iostream>
#include <vector>
#include <cstdlib>

/********************************************************************************
* dense_layer: Dense-lager f�r implementering i neurala n�tverk. Nodernas
*              parametrar (utsignal, bias, fel och vikter) lagras via vektorer.
********************************************************************************/
struct dense_layer
{
   std::vector<double> output;               /* Nodernas utsignaler. */
   std::vector<double> error;                /* Nodernas avvikelser/felv�rden. */
   std::vector<double> bias;                 /* Nodernas bias/vilov�rden. */
   std::vector<std::vector<double>> weights; /* Nodernas vikter. */

   /********************************************************************************
   * dense_layer: Skapar ett nytt tomt dense-lager.
   ********************************************************************************/
   dense_layer(void) { }

   /********************************************************************************
   * dense_layer: Skapar och initierar ett nytt dense-lager med angivet antal
   *              noder samt vikter per nod.
   *
   *              - num_nodes  : Antalet noder i det nya lagret.
   *              - num_weights: Antalet vikter per nod i det nya lagret.
   ********************************************************************************/
   dense_layer(const std::size_t num_nodes,
               const std::size_t num_weights)
   {
      this->resize(num_nodes, num_weights);
      return;
   }

   /********************************************************************************
   * ~dense_layer: Nollst�ller dense-lager automatiskt innan objektet raderas.
   ********************************************************************************/
   ~dense_layer(void)
   {
      this->clear();
      return;
   }

   /********************************************************************************
   * clear: Nollst�ller dense-lager genom att t�mma vektorer.
   ********************************************************************************/
   void clear(void)
   {
      this->output.clear();
      this->error.clear();
      this->bias.clear();
      this->weights.clear();
      return;
   }

   /********************************************************************************
   * resize: S�tter nytt antal noder och vikter per nod i angivet dense-lager.
   *         Alla bias och vikter tilldelas randomiserade startv�rden mellan 0 - 1,
   *         �vriga parametrar s�tts till 0.
   * 
   *         - num_nodes  : Nytt antal noder i dense-lagret.
   *         - num_weights: Nytt antal vikter per nod i dense-lagret.
   ********************************************************************************/
   void resize(const std::size_t num_nodes,
               const std::size_t num_weights)
   {
      this->clear();

      this->output.resize(num_nodes, 0);
      this->error.resize(num_nodes, 0);
      this->bias.resize(num_nodes, 0);
      
      this->weights.resize(num_nodes, std::vector<double>(num_weights, 0));

      for (std::size_t i = 0; i < this->num_nodes(); ++i)
      {
         this->bias[i] = this->get_random();

         for (std::size_t j = 0; j < this->num_weights(); ++j)
         {
            this->weights[i][j] = this->get_random();
         }
      }

      return;
   }

   /********************************************************************************
   * get_random: Returnerar ett randomiserat flyttal mellan 0 - 1.
   ********************************************************************************/
   double get_random(void)
   {
      return static_cast<double>(std::rand()) / RAND_MAX;
   }

   /********************************************************************************
   * num_nodes: Returnerar antalet noder i aktuellt dense-lager.
   ********************************************************************************/
   std::size_t num_nodes(void) const
   {
      return this->output.size();
   }

   /********************************************************************************
   * num_weights: Returnerar antalet vikter per nod i aktuellt dense-lager.
   ********************************************************************************/
   std::size_t num_weights(void) const
   {
      if (this->weights.size())
      {
         return this->weights[0].size();
      }
      else
      {
         return 0;
      }
   }
};

#endif /* DENSE_LAYER_HPP_ */