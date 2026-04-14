# Analysis

## Part 1

### What happens if you use `delete` on the array?

Using `delete` on an array allocated with `new[]` is incorrect. The correct way is to use `delete[]`. If `delete` is used instead, the program enters undefined behavior. This may lead to incomplete destruction, memory errors, or unpredictable runtime problems.

### What happens if you forget to call `delete` at all?

If `delete` is never called, the allocated memory is not released. This creates a memory leak. In a short program the effect may be small, but in larger systems or long-running programs, repeated leaks can waste memory and hurt performance and stability.

### Can you call `delete` twice on the same pointer? What did you observe?

Calling `delete` twice on the same pointer is unsafe and also leads to undefined behavior. A program may crash immediately, or it may seem to run normally while silently corrupting memory. This is dangerous because the bug may be hard to detect.

---

## Part 2

### What was wrong with deleting the same pointer twice?

Deleting the same pointer twice means trying to free memory that has already been released. This is a serious memory error. It can cause crashes, data corruption, or unpredictable behavior.

### What was wrong with assigning a new object to the pointer without freeing the old one first?

When a pointer is overwritten before the old memory is released, the original object becomes unreachable. This creates a memory leak because the program no longer has a way to free that memory.

### What was wrong with using `delete` instead of `delete[]` for the array?

An array created with `new[]` must be destroyed with `delete[]`. Using `delete` instead is a mismatch between allocation and deallocation. This can prevent proper destruction and can lead to undefined behavior.

---

## Part 3

### Why is the copy constructor deleted?

The copy constructor is deleted to prevent two handles from owning the same raw pointer at the same time. If copying were allowed, both objects might try to delete the same memory, which could cause a double deletion error.

### Why is move semantics allowed?

Move semantics are allowed because ownership can be transferred safely from one object to another. After the transfer, only one object remains responsible for the memory. This keeps ownership clear and avoids double deletion.

### What happens if a destructor is not defined?

If no destructor is defined, the owned memory is not released automatically when the handle goes out of scope. That would cause a memory leak and defeat the purpose of using the handle in the first place.

### How does the test program demonstrate safe cleanup?

The test program shows that the managed object is destroyed automatically when the handle leaves scope. No manual `delete` call is needed. This demonstrates automatic and safer resource cleanup.

---

## Part 4

### How does the shared handle work?

The shared handle allows multiple objects to refer to the same dynamically allocated trade. Instead of giving ownership to only one object, it keeps track of how many handles are using the same resource.

### Why is copying allowed in the shared version?

Copying is allowed because shared ownership is the main goal of this design. Each copy increases the reference count, which records how many active handles still refer to the same resource.

### When is the underlying object deleted?

The underlying object is deleted only when the last handle is destroyed. At that point, the reference count reaches zero, which means no active owner remains.

### What is the main difference between this handle and the one in Part 3?

The handle in Part 3 supports exclusive ownership, so only one object can manage the resource at a time. The shared version supports multiple owners and uses reference counting to decide when cleanup should happen.

---

## Part 5

### What are the three biggest risks of manual memory management?

The three biggest risks are memory leaks, double deletion or dangling pointers, and mismatches between allocation and deallocation. All of these can cause crashes, unstable behavior, or hard-to-find bugs.

### What real-world problems could occur in HFT systems due to memory leaks or fragmentation?

In high-frequency trading systems, memory leaks can slowly increase memory usage and reduce reliability over time. Memory fragmentation can make allocation less efficient and increase latency. In a system where speed and stability are critical, these problems can affect performance, increase operational risk, and potentially lead to trading disruptions.

### How does RAII reduce the risk of bugs?

RAII reduces bugs by tying resource cleanup to object lifetime. When an object goes out of scope, its destructor automatically releases the resource. This makes cleanup more consistent and reduces the chance of forgetting to free memory.

### What tradeoffs exist between manual and automatic memory management in performance-critical code?

Manual memory management can offer more direct control and may help optimize performance in some situations, but it is also easier to get wrong. Automatic memory management is safer and easier to maintain, but it may introduce extra abstraction or overhead. In performance-critical systems, the tradeoff is usually between maximum control and reduced bug risk.
