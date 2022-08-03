# ALGORITHM
Least Recently Used (LRU) cache algorithm keeps recently used items near the front of cache. Whenever a new item is accessed, the LRU places it at the head of the cache. When the cache reaches to its capacity, items that have been accessed less recently will be removed starting from the end of the cache.
# HOW IT WORKS?

Generally, LRU algorithm is implemented with HashMap and Doubly Linked List, Queue.

**newNode()** : This function creates a new node which contains the page and the pointer to the next and the previous node.

**createQueue()** : This function creates the queue with the provided size and initialize the the front and rear pointer as NULL.

**createHash()** : It creates an array with the provided size and initialize all the values with NULL.

**areAllFramesFull()** : This function returns the Boolean value based on the  condition whether the queue is full or not.

**isQueueEmpty()** : Returns the Boolean value based on whether the queue is empty or not.

**dequeue()** : Based on the property of queue (First In First Out) the queue will dequeue the rear node.

**enqueue()** : It will create the new node to the front of the queue and its node value is stored in the hash at its respective page value.

**referencePage()** : It will check if the node is already present in the queue if so, it makes the node at the front of the queue and if the node is new to the queue it will make it as the front node of the queue. And at each time the function is called all the values present in the cache at the moment will be written into a file.

**getThePage()** : It will search for the required page in the queue if found, it will make the updates to the cache and return the value else it will return -1.

**printAll()** : This function will print all the values present at the moment in the cache to the console.

# OPERATIONS ON LRU :
**ADD :**

  &nbsp;&nbsp;&nbsp;&nbsp;•	Create new node for the given value and insert it to the head of the queue.
  
  &nbsp;&nbsp;&nbsp;&nbsp;•	Put the new node to HashMap with the given value as key.
  
  &nbsp;&nbsp;&nbsp;&nbsp;•	Size is increased by one.
  
**WHEN CACHE IS FULL :**

  &nbsp;&nbsp;&nbsp;&nbsp;•	Remove the last element(The one tail.prev is pointing) from the list.
  
  &nbsp;&nbsp;&nbsp;&nbsp;•	Create new node for the given value and insert it to the head of the linked list.
  
  &nbsp;&nbsp;&nbsp;&nbsp;•	Put the new node to HashMap with the given value as key.
  
  &nbsp;&nbsp;&nbsp;&nbsp;•	Size remains unchanged.
  
**GET :** 

  &nbsp;&nbsp;&nbsp;&nbsp;•	Find the given value in HashMap.
  
  &nbsp;&nbsp;&nbsp;&nbsp;•	If the corresponding node is not at the head position of the linked list, move it to head.
  
  &nbsp;&nbsp;&nbsp;&nbsp;•	Update the tail pointers accordingly.
  
  &nbsp;&nbsp;&nbsp;&nbsp;•	Return the value.

# DATA STRUCTURES :
Data Structures used in the project are,

 &nbsp;&nbsp;&nbsp;&nbsp;i)	Linked List

 &nbsp;&nbsp;&nbsp;&nbsp;ii)	Queue

 &nbsp;&nbsp;&nbsp;&nbsp;iii)	HashMap

**Linked List :**
	The doubly linked list is actually here for the purpose of keep tracking the next and the previous node at the same instance and linked list implementation of the data structure queue is used.

**Queue :**
	The data structure queue is used mainly to maintain the eviction order and also the  size of the cache is been regulated by the size of the queue. Whenever a new node is added the queue ‘s front pointer will be pointing to it. And the eviction is done at the rear pointer of the queue. The principle used in queue First In First Out (FIFO) plays a major role in the implementation of the LRU Cache. So the most recently accessed elements are tracked using the queue.

**HashMap :** 
	The HashMap largely reduces the complexity of the program while searching for the node as O(1). While looking for the node if the node is present in the hashmap make it as the front node of the queue, if the searched node is not present in the hashmap then insert the new node to the front of the queue.

# REAL – LIFE APPLICATION :

A simple website called ‘Sports’ has been created using Node JS to illustrate how the LRU Cache works.

The ‘localhost:3000’ is the url for the home page of the website and the other pages are followed with the url of ‘localhost:3000/r’ where r corresponds to the page number.

The url ‘localhost:3000/1’ corresponds to ‘Cricket’ page

The url ‘localhost:3000/2’ corresponds to ‘Football’ page

The url ‘localhost:3000/3’ corresponds to ‘Tennis’ page

The url ‘localhost:3000/4’ corresponds to ‘BasketBall’ page

The url ‘localhost:3000/5’ corresponds to ‘BaseBall’ page

**Home page :**

<p align="center" width="100%">
<img width="600" alt="ss1" src="https://user-images.githubusercontent.com/93649106/182632490-51c1efa9-2465-40fb-b362-7fdb9e003cb0.png">
</p>

Now the C program for the LRU cache is made to run.

<p align="center" width="100%">
<img width="600" alt="ss2" src="https://user-images.githubusercontent.com/93649106/182632831-41365a84-9210-4128-b1b5-6bdc3c7d8e3e.png">
</p>

The cache is created with the size of three. i.e. We can store only three webpages inside the cache, if the url is present in the cache while retrieving we can access the page else we will end up with 404 (not found) error.

<p align="center" width="100%">
<img width="566" alt="ss3" src="https://user-images.githubusercontent.com/93649106/182633013-96a2c4fe-9efb-47e7-bbe1-49971aee7cdb.png">
</p>

<p align="center" width="100%">
<img width="633" alt="ss4" src="https://user-images.githubusercontent.com/93649106/182633097-03e8e21a-2503-4994-ab79-c68f5423f63b.png">
</p>

<p align="center" width="100%">
<img width="621" alt="ss5" src="https://user-images.githubusercontent.com/93649106/182633112-26d5dcd2-a163-4b10-8dbb-5eef8b6eb232.png">
</p>

The value 3, 2, 1 have been added to the cache. We can visualize it by printing the elements in the cache from the front of the queue.

<p align="center" width="100%">
<img width="553" alt="ss6" src="https://user-images.githubusercontent.com/93649106/182633174-64d48c8b-fe00-423a-b921-75ab4851a5cd.png">
</p>

Now we can view the webpage which have the page number 1 or 2 or 3 but if we try to access the webpage other than this we will end up with the 404 error.

<p align="center" width="100%">
<img width="600" alt="ss7" src="https://user-images.githubusercontent.com/93649106/182633580-b2f239ec-3a50-4435-93a7-5035c0229c83.png">
</p>

<p align="center" width="100%">
<img width="600" alt="ss8" src="https://user-images.githubusercontent.com/93649106/182633633-b9fdcf74-cfbf-42a9-85c0-0546106d4f1c.png">
</p>

<p align="center" width="100%">
<img width="600" alt="ss9" src="https://user-images.githubusercontent.com/93649106/182633709-0bfb7f23-b661-4424-aa1c-7cb451edd9c9.png">
</p>

<p align="center" width="100%">
<img width="600" alt="ss10" src="https://user-images.githubusercontent.com/93649106/182634003-3101b14d-967e-48fe-b46c-f6b83a87a1cb.png">
</p>



Since the webpage ‘/4’ is not found in the cache we get the not found error.
Now a few modifications are done in the cache storage.

<p align="center" width="100%">
<img width="635" alt="ss11" src="https://user-images.githubusercontent.com/93649106/182634191-e0d148b8-53ba-41ab-b9aa-55b90332b9c3.png">
</p>

<p align="center" width="100%">
<img width="672" alt="ss12" src="https://user-images.githubusercontent.com/93649106/182634200-192797da-1467-4ed7-a3e2-c148eb225c08.png">
</p>

Now the page 4 is added to the cache, so the least recently used page 3 is evicted from the cache and 4 is added to the front of the queue. 

<p align="center" width="100%">
<img width="600" alt="ss13" src="https://user-images.githubusercontent.com/93649106/182634309-16d24d60-a546-487f-9182-7aa39669c213.png">
</p>

<p align="center" width="100%">
<img width="600" alt="ss14" src="https://user-images.githubusercontent.com/93649106/182634326-dbd3028e-6e89-438c-be52-50220fdfeb9d.png">
</p>

So now when we try to access the page 4 it will be accessed but when we try to access the page 3 it will show the not found error.

<p align="center" width="100%">
<img width="610" alt="ss15" src="https://user-images.githubusercontent.com/93649106/182634681-169edc5f-f103-4579-ab98-364b07668452.png">
</p>

<p align="center" width="100%">
<img width="595" alt="ss16" src="https://user-images.githubusercontent.com/93649106/182634720-e8b5d2a4-ab01-46e4-8202-af9387f6f5ee.png">
</p>

Since 2 is already present in the cache it will just shift to the front of the queue. i.e. The queue 4 1 2 will now became 2 4 1.
 And now the page 5 is added so the cache becomes 5 2 4 and so the page 1 is evicted from the cache.

<p align="center" width="100%">
<img width="600" alt="ss20" src="https://user-images.githubusercontent.com/93649106/182635076-29efdefa-e9ca-41fd-8e83-d53eaeddf4f1.png">
</p>

<p align="center" width="100%">
<img width="600" alt="ss17" src="https://user-images.githubusercontent.com/93649106/182635155-2290c431-d087-46b7-afa7-2381203aa935.png">
</p>


When we try to get a page not in the cache we will also end up with the 404 error.

<p align="center" width="100%">
<img width="554" alt="ss19" src="https://user-images.githubusercontent.com/93649106/182635299-6513b295-5c1b-4728-a6ba-aa36f91ea2a4.png">
</p>

<p align="center" width="100%">
<img width="600" alt="ss21" src="https://user-images.githubusercontent.com/93649106/182635395-78612bff-0a7b-46e9-b3f8-47ce2140c3ba.png">
</p>



The following project thus illustrates the implementation of the LRU Cache.

